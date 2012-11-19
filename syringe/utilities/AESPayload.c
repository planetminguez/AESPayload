/**
  * AESPayload Syringe - injectpois0n.c
  * Copyright (C) 2012 Dylan Laws
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libpois0n.h"
#include "libirecovery.h"
#define FILE_HISTORY_PATH "aes.log"
#ifdef COMMIT
#define STRINGIFY(x) #x
#define XSTRINGIFY(x) STRINGIFY(x)
#define COMMIT_STRING " (" XSTRINGIFY(COMMIT) ")"
#else
#define COMMIT_STRING ""
#endif
#define VERSION "2.5"
int upload_ibss();
int upload_ibss_payload();



void print_progress(double progress) {
	int i = 0;
	if(progress < 0) {
		return;
	}
    
	if(progress > 100) {
		progress = 100;
	}
    
	printf("\r[");
	for(i = 0; i < 50; i++) {
		if(i < progress / 2) {
			printf("=");
		} else {
			printf(" ");
		}
	}
    
	printf("] %3.1f%%", progress);
	if(progress == 100) {
		printf("\n");
	}
}
void print_pois0n_progress(double progress, void* data) {
	print_progress(progress);
}

int progress_cb(irecv_client_t client, const irecv_event_t* event) {
	if (event->type == IRECV_PROGRESS) {
		print_progress(event->progress);
	}
	return 0;
}

void help() {
    printf("\n");
    printf("AESPayload "VERSION";");
    printf("Usage: AESPayload [arg] (No brackets)\n");
    printf("==========================================================\n");
    printf("[-go] - Start process (please connect the device in DFU mode)\n");
    printf("[-irecovery] - Start irecovery shell in verbose mode\n");
    printf("==========================================================\n");
    printf("\n");
}
int main(int argc, char* argv[]) {
	
    if (argc > 1) {
        if (!strcmp(argv[1],"-go")){
            pois0n_init();
            pois0n_set_callback(&print_progress, NULL);
            
            info("Waiting for device to enter DFU mode\n");
            pois0n_is_ready();
            
            info("Found device in DFU mode\n");
            if(!pois0n_is_compatible()){
            pois0n_inject("2");
        }
            pois0n_exit();
        }if (!strcmp(argv[1],"-irecovery")) {
            system("build/irecovery -v -s");
        }
        
    }else {
        help();
    }
    


	return 0;
}
