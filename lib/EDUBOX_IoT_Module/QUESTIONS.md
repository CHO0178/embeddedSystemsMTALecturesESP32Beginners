Light module:
-Doxygen mít v cpp i v hpp? -> tam i tam

HumTemp module:
- Millis() ? yez


WaterLevel module:



Button module:
- Millis() ? yez


PIR module:

@startuml
title WebSocket

participant Klient
participant Server

Klient -> Server: Otevření WebSocket spojení
Server --> Klient: Spojení navázáno


Server <--> Klient: data (jen když se změní)

note right of Server
Server posílá data
jen při změně
end note

@enduml


@startuml
title HTTP Polling

participant Klient
participant Server

Klient -> Server: GET /data
Server --> Klient: odpověď

Klient -> Server: GET /data
Server --> Klient: odpověď

Klient -> Server: GET /data
Server --> Klient: odpověď

note right of Klient
Klient se ptá pravidelně,
i když se data nemění
end note

@enduml
