//stoneroad1.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
        set("long",@LONG
һ��������ͨ�˴��ʯ��·��������ȫ�µ������룬�������н�ͨ�
æ�ĵط����ɴ����Ͽɴ���۱�����Ǵ󱯵������շת�ɴ�����
Ժ����Ժ������Ҫ�ء�
LONG
	);
        set("outdoors","shaolin");
	set("exits", ([
	"west" : __DIR__ "huaishu4",
        "north" : __DIR__"dabeidia",
        "south" : __DIR__ "daxiong",
        "east" : __DIR__ "songshu2",
          ]));
        set("objects",([
          CLASS_D("shaolin") + "/hui-ru" : 1,
          __DIR__"npc/seng-bing3" : 2,
         
      ]));
	set("coor/x",50);
  set("coor/y",310);
   set("coor/z",120);
   setup();
}



