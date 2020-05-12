Mission : create a website that shows a map of the coronavirus using MapBox and John Hopkins COVID-19 data.

I've built it using Flask, cause it seems enough to for the mission.

Follow lines below to see the demo site

```
docker build -t 68ex_02:latest .
docker run -p 5000:5000 68ex_02
```


Data come from `https://github.com/CSSEGISandData/COVID-19/tree/master/csse_covid_19_data/csse_covid_19_daily_reports`
