//xianglu.c

inherit ROOM;

void create()
{
	set("short", "��¯");
        set("long",@LONG
�߹�ʯ��·�͵�������������¯�ԣ�����¯����ͭ���ͣ������˶��
¯���Ͼ����ο��˶������޼�������ͳ��ѵķ�ҵ�ʡ�¯�����������˵�
�Ƿ������֮����¯ǰ�㰸ǰ����λ������Զ���Ĥ�ݡ�
LONG
	);
        set("outdoors", "shaolin");
	set("exits", ([
	    "north" : __DIR__ "stoneroad2",
            "south" : __DIR__"sblu-1",
          ]));
        set("objects",([
	__DIR__"npc/xiang-ke" : 2,
]));
	set("coor/x",50);
  set("coor/y",260);
   set("coor/z",110);
   set("coor/x",50);
 set("coor/y",260);
   set("coor/z",110);
   setup();
}
