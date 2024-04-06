package com.Server.ec2server.http;

public class HttpRequest extends HttpMessage{

    private HttpMethod method;
    private String requestTarget;
    private String originalHttpVersion;
    private HttpVersion bestCompatibleHttpVersion;

    HttpRequest(){



    }





    public HttpMethod getMethod() {
        return method;
    }

    void setMethod(String method) throws HttpParsingException{
        for(HttpMethod httpMethod : HttpMethod.values()){
            if(httpMethod.name().equals(method)){
                this.method = httpMethod;
                return;
            }
        }throw new HttpParsingException(HttpStatusCode.SERVER_ERROR_501_NOT_IMPLEMENTED);
    }


    public String getRequestTarget() {
        return requestTarget;
    }


    public void setRequestTarget(String string) throws HttpParsingException {
        if(string == null || string.isEmpty()) throw new HttpParsingException(HttpStatusCode.SERVER_ERROR_500_INTERNAL_SERVER_ERROR);
        this.requestTarget = string;
    }


    public HttpVersion getBestCompatibleHttpVersion() {
        return bestCompatibleHttpVersion;
    }

    public String getOriginalHttpVersion() {
        return originalHttpVersion;
    }


    public void setHttpVersion(String version) throws HttpParsingException, BadHttpVersionException {

        originalHttpVersion = version;
        this.bestCompatibleHttpVersion = HttpVersion.getBestCompatibleVersion(version);
        if(bestCompatibleHttpVersion == null) throw new HttpParsingException(HttpStatusCode.SERVER_ERROR_505_HTTP_VERSION_NOT_SUPPORTED);

    }










}
