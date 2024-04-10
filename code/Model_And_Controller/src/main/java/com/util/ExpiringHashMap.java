package com.util;

import java.util.Collection;
import java.util.HashMap;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class ExpiringHashMap<I, L> extends HashMap<I, L> {

    private final HashMap<I, Long> creationTimes;
    private final ScheduledExecutorService executor;
    private final long expirationTimeMillis = 1000 * 60 * 60 * 5; // 5 hours


    public ExpiringHashMap(){
        creationTimes = new HashMap<>();
        executor = Executors.newSingleThreadScheduledExecutor();
    }


    @Override
    public L put(I key, L value){

        creationTimes.put(key, System.currentTimeMillis());
        L previousValue = super.put(key, value);
        executor.schedule(() -> {
            long creationTime = creationTimes.getOrDefault(key, 0L);
            long currentTime = System.currentTimeMillis();
            if (currentTime - creationTime > expirationTimeMillis) {
                super.remove(key);
                creationTimes.remove(key);
            }

        }, expirationTimeMillis, TimeUnit.MILLISECONDS);
        return previousValue;
    }

    @Override
    public L remove(Object key){
        creationTimes.remove(key);
        return super.remove(key);
    }

    @Override
    public Collection<L> values() {
        return super.values();
    }


}
