inherit ROOM;

void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ�����ݳǡ���������һ����
·ͨ�����ݡ�
long);
set("outdoors", "suzhou");                        
set("objects",([
__DIR__"npc/yetu" : 2,
]));
set("exits",([
"southwest" : "/d/hz/shanlu1",
"southeast" : "/d/jiaxing/road2",
"north" : __DIR__"southgate",
"northeast" : __DIR__"qsgdao1",
]));
set("coor/x",110);
  set("coor/y",-270);
   set("coor/z",0);
   setup();
}
