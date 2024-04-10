package com.util;

import java.util.HashMap;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class ExpiringHashMap<I, L> {

    private final HashMap<I, L> map;
    private final ScheduledExecutorService executor;
    private final int expirationTime = 1000 * 60 * 60 * 24; // 1 day

    public ExpiringHashMap(){
        map = new HashMap<>();
        executor = Executors.newSingleThreadScheduledExecutor();
    }

    public void put(I key, L value){
        map.put(key, value);
        executor.schedule(() -> map.remove(key), expirationTime, TimeUnit.MILLISECONDS);
    }

    public L get(I key){
        return map.get(key);
    }

    public void remove(I key){
        map.remove(key);
    }

}
