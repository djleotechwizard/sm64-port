#include "httpd.h"
#include <sys/stat.h>
#include <pthread.h>
#include <types.h>
#define CHUNK_SIZE 1024 // read 1024 bytes at a time

// Public directory settings
#define PUBLIC_DIR "./public"
#define INDEX_HTML "/index.html"
#define NOT_FOUND_HTML "/404.html"

void thread_function() {
    char *port = "8000";
    serve_forever(port);
}


void initialize_server() {
    pthread_t pid;
    pthread_create(&pid, NULL, thread_function, NULL);
}

extern struct MarioState *gMarioState;


void route() {
    ROUTE_START()

    GET("/testGET") {
        HTTP_200;
        printf("Test GET");
        printf("%d", gMarioState->numCoins);
    }

    POST("/testPOST") {
        HTTP_201;
        printf("Wow, seems that you POSTed %d bytes.\n", payload_size);
        printf("Fetch the data using `payload` variable.\n");
        if (payload_size > 0)
            printf("Request body: %s", payload);
    }

    ROUTE_END()
}
