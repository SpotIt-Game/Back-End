package com.Server.ec2server.util;
import com.fasterxml.jackson.databind.*;

import java.io.IOException;

public class Json {

    private static ObjectMapper myObjectMapper = defaultObjectMapper();


    private static ObjectMapper defaultObjectMapper() {
        ObjectMapper om = new ObjectMapper();
        om.configure(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES, false);
        return om;
    }


    public static JsonNode parse(String json) throws IOException {
        return myObjectMapper.readTree(json);
    }



    public static <T> T fromJson(JsonNode node, Class<T> clazz) throws IOException {
        return myObjectMapper.treeToValue(node, clazz);
    }


    public static JsonNode toJson(Object obj) {
        return myObjectMapper.valueToTree(obj);
    }



    private static String generateJson(Object obj, boolean pretty) throws IOException {

        ObjectWriter ow = myObjectMapper.writer();
        if(pretty)  ow = ow.with(SerializationFeature.INDENT_OUTPUT);
        return ow.writeValueAsString(obj);
    }



    public String stringify(Object obj) throws IOException {
        return generateJson(obj, false);
    }


    public String stringifyPretty(Object obj) throws IOException {
        return generateJson(obj, true);
    }











}
