//stoneroad3.c

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
        set("outdoors", "shaolin");
	set("exits", ([
             "east" : __DIR__ "brtang",
             "north" : __DIR__"celang2",
             "west" : __DIR__"stoneroad2", 	  
          ]));
	set("coor/x",60);
  set("coor/y",270);
   set("coor/z",110);
   setup();
}



