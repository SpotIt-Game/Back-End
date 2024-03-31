import java.util.*;
import java.net.http.*;
import java.net.URI;




public class Main{


    public static ArrayList<Integer> shuffleCards(ArrayList<Integer> ids){

        Collections.shuffle(ids);
        return ids;

    }

    public boolean equals(String url1, String url2){
        return url1.equals(url2);
    }

    


    
    public static void main(String[] args) throws IOException, InterruptedException{

        HttpClient httpclient = HttpClient.newHttpClient();
        HttpRequest request = HttpRequest.newBuilder().uri(URI.create("https://ejemplo.com/api/endpoint")).build();
         
        HttpResponse<String> response = httpClient.send(request, HttpResponse.BodyHandlers.ofString());

        int statusCode = response.statusCode();
        System.out.println("Código de estado: " + statusCode);

        String responseBody = response.body();
        System.out.println("Cuerpo de la respuesta: " + responseBody);
    
    }

    
    
}

/*

*/ 