inherit ROOM;

void create()
{
        set("short", "��ͬ");
        set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ������
ͨ��С�����
LONG
        );
        set("objects", ([
     __DIR__"npc/liumangtou"    : 1,
        ]) );

        set("exits", ([
        "east" : __DIR__"hutong2",
        "southwest" : __DIR__"hutong",
]));
        set("coor/x",130);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}
