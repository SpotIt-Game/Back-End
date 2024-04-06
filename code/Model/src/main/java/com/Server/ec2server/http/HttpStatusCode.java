package com.Server.ec2server.http;

public enum HttpStatusCode {

    //client errors
    CLIENT_ERROR_400_BAD_REQUEST(400, "BadRequest"),
    CLIENT_ERROR_401_METHOD_NOT_ALLOWED(401, "MethodNotAllowed"),
    CLIENT_ERROR_414_BAD_REQUEST(414, "URI Too Long"),


    //server errors
    SERVER_ERROR_500_INTERNAL_SERVER_ERROR(500, "Internal Server Error"),
    SERVER_ERROR_501_NOT_IMPLEMENTED(501, "Not Implemented"),
    SERVER_ERROR_505_HTTP_VERSION_NOT_SUPPORTED(505, "HTTP Version Not Supported");




    public final int STATUS_CODE;
    public final String MESSAGE;


    HttpStatusCode(int statusCode, String message){
        this.STATUS_CODE = statusCode;
        this.MESSAGE = message;
    }


}
