package com.Server.ec2server.http;

public enum HttpMethod {

    GET, HEAD, POST;

    public static final int MAX_LENGTH;


    static{

        int tmpMaxLength = -1;
        for(HttpMethod method : values()) tmpMaxLength = Math.max(tmpMaxLength, method.name().length());
        MAX_LENGTH = tmpMaxLength;

    }

}
