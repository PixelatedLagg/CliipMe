//TUTORIAL APPLICATION

#include <wups.h>
#include <nsysnet/socket.h>
#include "include/libutilswut/utils/logger.h"
#include <coreinit/filesystem.h>

// Mandatory plugin information.
WUPS_PLUGIN_NAME("CliipMe");
WUPS_PLUGIN_DESCRIPTION("Game Capture");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("Pixelated_Lagg");
WUPS_PLUGIN_LICENSE("GNU");

// Gets called once the loader exists.
ON_APPLICATION_START(){
    socket_lib_init();
    log_init();
    DEBUG_FUNCTION_LINE("ON_APPLICATION_PLUGIN\n");
}

// Lets replace FSOpenFile
DECL_FUNCTION(int, FSOpenFile, FSClient *pClient, FSCmdBlock *pCmd, const char *path, const char *mode, int *handle, int error) {
    int result = real_FSOpenFile(pClient, pCmd, path, mode, handle, error);

    log_printf("FSOpenFile called for folder %s! Result %d\n",path,result);
    return result;
}

// Replace it.
WUPS_MUST_REPLACE(FSOpenFile, WUPS_LOADER_LIBRARY_COREINIT, FSOpenFile);