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
               __DIR__"npc/liumang"    : 2,
     __DIR__"npc/liumangtou"    : 1,
        ]) );

        set("exits", ([
        "west" : __DIR__"hutong1",
"southeast" : __DIR__"dongdajie2",
]));
        set("coor/x",140);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}
