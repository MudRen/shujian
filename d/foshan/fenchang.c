//fenchang.c by zly

inherit ROOM;

void create()
{
        set("short", "�س�");
        set("long",
"������һ����ɭ�ķس����Եúܻ�����վ������ʱ�䳤�ˣ��е�ë
���Ȼ�ĸо���������������뿪�ɡ�\n"
        );
        set("outdoors", "��ɽ");
        set("exits", ([
            "southwest" : __DIR__"xiaolu1",
]));
        set("coor/x",10);
  set("coor/y",-480);
   set("coor/z",0);
   setup();
}

