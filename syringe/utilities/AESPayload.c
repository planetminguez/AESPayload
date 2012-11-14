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
#include <unistd.h>
#include "libpois0n.h"
#ifdef COMMIT
#define STRINGIFY(x) #x
#define XSTRINGIFY(x) STRINGIFY(x)
#define COMMIT_STRING " (" XSTRINGIFY(COMMIT) ")"
#else
#define COMMIT_STRING ""
#endif

#define LOADIBEC_VERSION "2.00"

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
/*void init_shell(irecv_client_t client) {
	irecv_error_t error = 0;
	load_command_history();
	irecv_event_subscribe(client, IRECV_PROGRESS, &progress_cb, NULL);
	irecv_event_subscribe(client, IRECV_RECEIVED, &received_cb, NULL);
	irecv_event_subscribe(client, IRECV_PRECOMMAND, &precommand_cb, NULL);
	irecv_event_subscribe(client, IRECV_POSTCOMMAND, &postcommand_cb, NULL);
	while (!quit) {
		error = irecv_receive(client);
        
		if (error != IRECV_E_SUCCESS) {
			debug("%s\n", irecv_strerror(error));
			break;
		}
        
		char* cmd = readline("> ");
		if (cmd && *cmd) {
			error = irecv_send_command(client, cmd);
			if (error != IRECV_E_SUCCESS) {
				quit = 1;
			}
            
			append_command_to_history(cmd);
			free(cmd);
		}
	}
}*/
void help() {
    printf("\n");
    printf("AESPayload; uploads the greenpois0n custom iBSS payload to device\n");
    printf("Usage: AESPayload [arg] (No brackets)\n");
    printf("==========================================================\n");
    printf("[-go] - Start process (please connect the device in DFU mode)\n");
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
        }
        
        
    }else {
        help();
    }
    


	return 0;
}
