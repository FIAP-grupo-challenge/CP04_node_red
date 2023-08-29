## Desenvolvedores
1. Nome: Lucas Fernandes Joaquim, RM: 551313
2. Nome: Gustavo Ferreira Lopes, RM: 98887
3. Nome: heitor freire dos anjos, RM: 552165
4. Nome: Rodrigo Fernandes dos Santos, RM: 98896
5. Nome: Enzo Silva Cataldi, RM: 99826

## Descrição ex 1
1. Utilizamos um node inject para iniciar o request na API
2. com o node http request foi realizada o GET na API com os seguintes links:

    Link para o dashhboard de São Paulo:
     ```text
    https://api.openweathermap.org/data/2.5/weather?lat=-23.5489&lon=-46.6388&appid=d900df66386cc17a30b1d5b08ee0b737
    ```
    Link para o dashhboard de Salvador:
     ```text
    https://api.openweathermap.org/data/2.5/weather?lat=-12.9704&lon=-38.5124&appid=d900df66386cc17a30b1d5b08ee0b737
    ```
3. Logo em seguida As infomações obtidas neste GET são tranformadas em JSON (objeto java) pelo node JSON
4. Apos a conversão para JSON as informações são isoladas e processadas por nodes function

    exemplo codigo node function temperatura atual:
     ```text
     var temp = msg.payload["main"]["temp"];
    temp = temp - 273;
    temp = temp.toFixed(2)
    msg.payload = temp;
    return msg;
    ```
5. por fin as informações ja processadas são enviadas para seus respectivos Gauges, que de acordo com o link que deu origem a suas informações, seu Gauge estara localizado no dashboard São paulo ou Salvador


## Descrição ex 2
1. O circuito do arduino passara as informações para a porta COM1
2. já No node red a pora COM1 sera capturada por um node 'serial in'
3. o node serial in tem seu msg.payload convertido para um JSON (objeto java)
4. O valor distancia é extraido do JSON por um node function com o seguinte codigo 
    ```text
    var distancia = msg.payload["Distancia"];
    msg.payload = distancia;
    return msg;
    ```
5. Por fim o Gauge recebe a informação como output da function
6. O gauge esta em display no dashboard HOME

### Circuito arduino

<div align="center">
  <a href="#">
    <img src="./Circuito exe2.png" alt="Logo" width="auto" height="auto">
  </a>
</div>