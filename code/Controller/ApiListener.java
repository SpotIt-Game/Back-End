import java.util.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;
import org.springframework.web.client.RestTemplate;
import com.google.gson.Gson;
import com.google.gson.JsonObject;



@Component
public class ApiListener {

    private final String API_URL = "http://localhost:9000/move2/";
    private final RestTemplate restTemplate;
    private final Map<Integer, Lobby> lobbies = new HashMap<>();



    @Autowired
    public ApiListener(RestTemplate restTemplate) {
        this.restTemplate = restTemplate;
    }

    @Scheduled(fixedRate = 50) // every 50 miliseconds
    public void listenToApi() throws Exception {
        
        JsonObject jsonGod = receiveData(API_URL);
        int move = jsonGod.get("move").getAsInt();
        int id_lobby = jsonGod.get("id_lobby").getAsInt();

        if (move == 1) lobbies.put(id_lobby, new Lobby(jsonGod));
        else if (move == 2) sendData(API_URL, new Gson().toJson(Main.lobbies.get(id_lobby).verifyMove(jsonGod)));
        else sendData(API_URL, new Gson().toJson(Main.lobbies.get(id_lobby).calculateWinner(jsonGod)));
        
    }

    public JsonObject receiveData(String apiUrl) {
        return restTemplate.getForObject(apiUrl, JsonObject.class);
    }

    public void sendData(String apiUrl, String jsonBody) {
        restTemplate.postForObject(apiUrl, jsonBody, String.class);
        System.out.println("JSON enviado con éxito.");
    }


}
