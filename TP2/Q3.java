package TP2;

import java.util.*;
//import java.util.stream.Collectors;
import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

class Main {
    public static void main(String[] args) {
        String path = "/tmp/pokemon.csv";
        List<Pokemon> list = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(new FileReader(path))) {
            String line = br.readLine();
            line = br.readLine();

            while (line != null) {
                Pokemon pk = new Pokemon();
                pk.ler(line);
                list.add(pk);
                line = br.readLine();
            }
        } catch (IOException e) {}

        Scanner scanner = new Scanner(System.in);
        while (true) {
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("FIM")) {
                break;
            }
            

            try {
                int id = Integer.parseInt(input);
                boolean found = false;

                for (Pokemon p : list) {
                    if (p.getId() == id) {
                        p.imprimir();
                        found = true;
                        if(found==false){

                        }
                        break;
                    }
                }
            } catch (NumberFormatException e) {}
        }



        scanner.close();
    }
}


class Pokemon {
    private int id;
    private int gen;
    private String nome;
    private String description;
    private List<String> types;
    private List<String> abilities;
    private double weight;
    private double height;
    private int captureRate;
    private boolean isLegendary;
    private LocalDate captureDate;

    public Pokemon() {}

    public Pokemon(int id, int gen, String nome, String description, List<String> types, List<String> abilities,
                   double weight, double height, int captureRate, boolean isLegendary, LocalDate captureDate) {
        setId(id);
        setGen(gen);
        setNome(nome);
        setDescription(description);
        setTypes(types);
        setAbilities(abilities);
        setWeight(weight);
        setHeight(height);
        setCaptureRate(captureRate);
        setIsLegendary(isLegendary);
        setCaptureDate(captureDate);
    }

    public int getId() { return id; }
    public int getGen() { return gen; }
    public String getNome() { return nome; }
    public String getDescription() { return description; }
    public List<String> getTypes() { return types; }
    public List<String> getAbilities() { return abilities; }
    public double getWeight() { return weight; }
    public double getHeight() { return height; }
    public int getCaptureRate() { return captureRate; }
    public boolean getIsLegendary() { return isLegendary; }
    public LocalDate getCaptureDate() { return captureDate; }

    public void setId(int id) { this.id = id; }
    public void setGen(int gen) { this.gen = gen; }
    public void setNome(String nome) { this.nome = nome; }
    public void setDescription(String description) { this.description = description; }
    public void setTypes(List<String> types) { this.types = types; }
    public void setAbilities(List<String> abilities) { this.abilities = abilities; }
    public void setWeight(double weight) { this.weight = weight; }
    public void setHeight(double height) { this.height = height; }
    public void setCaptureRate(int captureRate) { this.captureRate = captureRate; }
    public void setIsLegendary(boolean isLegendary) { this.isLegendary = isLegendary; }
    public void setCaptureDate(LocalDate captureDate) { this.captureDate = captureDate; }

    public void ler(String array) {
        String[] dados = array.split("(,?=(?:[^\\\"]*\\\"[^\\\"]*\\\")*[^\\\"]*$)");

        setId(dados[0].isEmpty() ? 0 : Integer.parseInt(dados[0]));
        setGen(dados[1].isEmpty() ? 0 : Integer.parseInt(dados[1]));
        setNome(dados[2]);
        setDescription(dados[3]);

        ArrayList<String> typesList = new ArrayList<>();
        if (!dados[4].isEmpty()) typesList.add(dados[4].trim());
        if (!dados[5].isEmpty()) typesList.add(dados[5].trim());
        setTypes(typesList);

        ArrayList<String> abilitiesList = parseAbilities(dados[6]);
        setAbilities(abilitiesList);

        setWeight(dados[7].isEmpty() ? 0.0 : Double.parseDouble(dados[7]));
        setHeight(dados[8].isEmpty() ? 0.0 : Double.parseDouble(dados[8]));
        setCaptureRate(dados[9].isEmpty() ? 0 : Integer.parseInt(dados[9]));
        setIsLegendary(dados[10].equals("1") || dados[10].equalsIgnoreCase("true"));

        if (!dados[11].isEmpty()) {
            LocalDate date = parseDate(dados[11]);
            setCaptureDate(date);
        }
    }

    private ArrayList<String> parseAbilities(String abilitiesStr) {
        abilitiesStr = abilitiesStr.replace("[", "").replace("]", "").trim();
        if (abilitiesStr.isEmpty()) {
            return new ArrayList<>();
        }
        String[] abilitiesArray = abilitiesStr.split(",\\s*");
        return new ArrayList<>(Arrays.asList(abilitiesArray));
    }

    private LocalDate parseDate(String dateStr) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        return LocalDate.parse(dateStr, formatter);
    }

    public void imprimir() {

    }


    @Override
    public Pokemon clone() {
        List<String> typesClone = new ArrayList<>(types);
        List<String> abilitiesClone = new ArrayList<>(abilities);
        return new Pokemon(id, gen, nome, description, typesClone, abilitiesClone, weight, height, captureRate, isLegendary, captureDate);
    }
}