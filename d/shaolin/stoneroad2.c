//stoneroad2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
        set("long",@LONG
һ��ƽ��������ʯ·��·����������ɮ��ɹ������Ϣ֮�á������
��ִ���㣬����ͨ����һЩæµ��ɮ�£����Ҵҵı��۶�ȥ���ƺ���ʲôҪ
������һ�ӻ���ɮ����ִ�䵶����������Ѳ�ӡ�
LONG
	);
        set("outdoors","haolin");
	set("exits", ([
	    "south" : __DIR__ "xianglu",
            "east" : __DIR__ "stoneroad3",
            "north" : __DIR__ "dxshijie",
             "west" : __DIR__ "stoneroad4",
          ]));
        set("objects",([
          CLASS_D("shaolin") + "/hui-se" : 1,
          __DIR__"npc/seng-bing3" : 2,
         
      ]));
	set("coor/x",50);
  set("coor/y",270);
   set("coor/z",110);
   set("coor/x",50);
 set("coor/y",270);
   set("coor/z",110);
   setup();
}
