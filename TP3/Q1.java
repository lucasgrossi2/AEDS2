package TP3;

import java.io.IOException;
import java.io.RandomAccessFile;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.*;
import java.nio.charset.Charset;

class Creature {

    private int identifier;
    private int gen;
    private String title;
    private String details;
    private List<String> typeList;
    private List<String> abilityList;
    private double mass;
    private double size;
    private int catchRate;
    private boolean legendaryStatus;
    private LocalDate captureDay;

    public Creature() {
        identifier = 0;
        gen = 0;
        title = "";
        details = "";
        typeList = null;
        abilityList = null;
        mass = 0.0;
        size = 0.0;
        catchRate = 0;
        legendaryStatus = false;
        captureDay = null;
    }

    public Creature(int identifier, int gen, String title, String details, List<String> typeList, List<String> abilityList, double mass, double size, int catchRate, boolean legendaryStatus, LocalDate captureDay) {
        this.identifier = identifier;
        this.gen = gen;
        this.title = title;
        this.details = details;
        this.typeList = typeList;
        this.abilityList = abilityList;
        this.mass = mass;
        this.size = size;
        this.catchRate = catchRate;
        this.legendaryStatus = legendaryStatus;
        this.captureDay = captureDay;
    }

    public int getIdentifier() {
        return identifier;
    }
    public void setIdentifier(int identifier) {
        this.identifier = identifier;
    }

    public int getGen() {
        return gen;
    }
    public void setGen(int gen) {
        this.gen = gen;
    }

    public String getTitle() {
        return title;
    }
    public void setTitle(String title) {
        this.title = title;
    }

    public String getDetails() {
        return details;
    }
    public void setDetails(String details) {
        this.details = details;
    }

    public List<String> getTypeList() {
        return typeList;
    }
    public void setTypeList(List<String> typeList) {
        this.typeList = typeList;
    }

    public List<String> getAbilityList() {
        return abilityList;
    }
    public void setAbilityList(List<String> abilityList) {
        this.abilityList = abilityList;
    }

    public double getMass() {
        return mass;
    }
    public void setMass(double mass) {
        this.mass = mass;
    }

    public double getSize() {
        return size;
    }
    public void setSize(double size) {
        this.size = size;
    }

    public int getCatchRate() {
        return catchRate;
    }
    public void setCatchRate(int catchRate) {
        this.catchRate = catchRate;
    }

    public boolean isLegendaryStatus() {
        return legendaryStatus;
    }
    public void setLegendaryStatus(boolean legendaryStatus) {
        this.legendaryStatus = legendaryStatus;
    }

    public LocalDate getCaptureDay() {
        return captureDay;
    }
    public void setCaptureDay(LocalDate captureDay) {
        this.captureDay = captureDay;
    }

    @Override
    public String toString() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        return "[#" + identifier + " -> " + title + ": " + details + " - " + formatTypeList(typeList) + " - " + formatList(abilityList) + " - " + mass + "kg - " + size + "m - " + catchRate + "% - " + legendaryStatus + " - " + gen + " gen] - " + captureDay.format(formatter);
    }

    public String formatList(List<String> list) {
        return String.join(",", list);
    }

    public String formatTypeList(List<String> list) {
        if(list.get(1) != null) {
            return "['" + list.get(0) + "', '" + list.get(1) + "']";
        } else {
            return "['" + list.get(0) + "']";
        }
    }

    public void display() {
        System.out.println(toString());
    }

    public boolean hasIdentifier(int num) {
        return num == identifier;
    }

    public Creature cloneCreature() {
        return new Creature(identifier, gen, title, details, typeList, abilityList, mass, size, catchRate, legendaryStatus, captureDay);
    }
}

class CreatureList {

    private Creature[] array;
    public int count;

    public CreatureList() {
        array = new Creature[801];
        count = 0;
    }

    public void addStart(Creature creature) throws Exception {
        if(count >= array.length) {
            throw new Exception("List is full!");
        }
        for(int i = count; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = creature;
        count++;
    }

    public void addEnd(Creature creature) throws Exception {
        if(count >= array.length) {
            throw new Exception("List is full!");
        }
        array[count] = creature;
        count++;
    }

    public void addAt(int pos, Creature creature) throws Exception {
        if(count >= array.length || pos < 0 || pos > count) {
            throw new Exception("List is full or invalid position!");
        }
        for(int i = count; i > pos; i--) {
            array[i] = array[i - 1];
        }
        array[pos] = creature;
        count++;
    }

    public Creature removeStart() throws Exception {
        if(count == 0) {
            throw new Exception("List is empty!");
        }
        Creature response = array[0];
        count--;
        for(int i = 0; i < count; i++) {
            array[i] = array[i + 1];
        }
        return response;
    }

    public Creature removeEnd() throws Exception {
        if(count == 0) {
            throw new Exception("List is empty!");
        }
        return array[--count];
    }

    public Creature removeAt(int pos) throws Exception {
        if(count == 0 || pos < 0 || pos >= count) {
            throw new Exception("List is empty or invalid position!");
        }
        Creature response = array[pos];
        count--;
        for(int i = pos; i < count; i++) {
            array[i] = array[i + 1];
        }
        return response;
    }

    public void displayAll() {
        for(int i = 0; i < count; i++) {
            System.out.println("[" + i + "] " + array[i].toString());
        }
    }
}

public class Q1 {

    static Creature[] creatures = new Creature[801];
    static DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    public static void populatePokedex() {
        String filePath = "/tmp/pokemon.csv";
        try {
            RandomAccessFile file = new RandomAccessFile(filePath, "r");
            Charset encoding = Charset.forName("UTF-8");
            file.readLine();
            String line;
            int index = 0;
            while((line = file.readLine()) != null) {
                line = new String(line.getBytes("ISO-8859-1"), encoding);
                String[] dataSplit = line.split("\"");
                String abilitiesData = dataSplit[1];
                String[] firstPart = dataSplit[0].split(",", -1);
                String[] secondPart = dataSplit[2].split(",", -1);
                
                int identifier = Integer.parseInt(firstPart[0]);
                int gen = Integer.parseInt(firstPart[1]);
                String title = firstPart[2];
                String details = firstPart[3];

                List<String> typeList = new ArrayList<>();
                typeList.add(firstPart[4]);
                typeList.add(firstPart[5].isEmpty() ? null : firstPart[5]);

                List<String> abilityList = new ArrayList<>();
                abilityList.add(abilitiesData);

                double mass = secondPart[1].isEmpty() ? 0 : Double.parseDouble(secondPart[1]);
                double size = secondPart[2].isEmpty() ? 0 : Double.parseDouble(secondPart[2]);
                int catchRate = secondPart[3].isEmpty() ? 0 : Integer.parseInt(secondPart[3]);
                boolean legendaryStatus = secondPart[4].charAt(0) != '0';
                LocalDate captureDay = LocalDate.parse(secondPart[5], formatter);

                Creature creature = new Creature(identifier, gen, title, details, typeList, abilityList, mass, size, catchRate, legendaryStatus, captureDay);
                creatures[index] = creature;
                index++;
            }
            file.close();
        } catch(IOException e) {
            e.printStackTrace();
        }
    }

    public static boolean isEnd(String input) {
        return input.equals("FIM");
    }

    public static void main(String[] args) throws NumberFormatException, Exception {
        populatePokedex();
        CreatureList list = new CreatureList();
        Scanner scanner = new Scanner(System.in);
        String input;
        do {
            input = scanner.nextLine();
            if(!isEnd(input)) {
                list.addEnd(creatures[Integer.parseInt(input) - 1].cloneCreature());
            }
        } while(!isEnd(input));

        int operations = scanner.nextInt();
        scanner.nextLine();
        for(int i = 0; i < operations; i++) {
            input = scanner.nextLine();
            String[] command = input.split(" ");
            switch (command[0]) {
                case "II":
                    list.addStart(creatures[Integer.parseInt(command[1]) - 1].cloneCreature());
                    break;
                case "IF":
                    list.addEnd(creatures[Integer.parseInt(command[1]) - 1].cloneCreature());
                    break;
                case "I*":
                    list.addAt(Integer.parseInt(command[1]), creatures[Integer.parseInt(command[2]) - 1].cloneCreature());
                    break;
                case "RI":
                    System.out.println("(R) " + list.removeStart().getTitle());
                    break;
                case "RF":
                    System.out.println("(R) " + list.removeEnd().getTitle());
                    break;
                case "R*":
                    System.out.println("(R) " + list.removeAt(Integer.parseInt(command[1])).getTitle());
                    break;
            }
        }
        list.displayAll();
        scanner.close();
    }
}
