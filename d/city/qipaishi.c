 
inherit ROOM; 
void create() 
{ 
        set("short", "������"); 
        set("long", @LONG 
����Ϊ������ʿ���ŵ��齫������,�Ǵ�ҷ��ɾ���ĺõط���
������ʾ:�Ĳ��а����彡����
LONG 
           ); 
        set("exits", ([ 
                 
                  "down" : "/d/city/chmiao"
           ]));

        set("objects",  ([  
                
//                 "/u/spiderii/mj" : 1,
            ])); 

        set("no_death", 1);
        set("no_fight", 1);
        setup();
}

