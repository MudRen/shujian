inherit ROOM;
void create()
{
        set("short","��ͬ");
        set("long", @LONG
����һ���ڰ��������С������з·�Ʈ����һ��������Ϣ������
��ͨ��С��������˾����ǲ������Ǳ���ȥ�ġ������߾ͻ�ص����д�·
�ˡ�������һ��С���Ϊ���������
LONG
);
        set("exits", ([ 
	    "south" : __DIR__"dongdajie3",
//     "west" : __DIR__"leitai",
        "northeast" : __DIR__"hutong1",

]));
        set("objects", ([
               __DIR__"npc/liumang"    : 2,
        ]) );

	set("coor/x",120);
  set("coor/y",-210);
   set("coor/z",0);
   set("incity",1);
	setup();
}

