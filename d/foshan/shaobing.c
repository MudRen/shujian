//shaobingtan 
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "�ձ�̯");
        set("long", @LONG
����ձ����������¿��ŵġ����治�����������һ����ը����һ����
¯���˵���С������ǳ����������ϵ���Ů���٣������������С�ꡣ
LONG
        );

        set("exits", ([
            "south" : __DIR__"dongjie2",

]));

        set("objects", ([
            __DIR__"npc/wanglaohan" : 1,
]));

        set("coor/x",20);
  set("coor/y",-520);
   set("coor/z",0);
   setup();

}
