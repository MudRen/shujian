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
             "west" : __DIR__ "lhtang",
             "north" : __DIR__"celang1",
             "east" : __DIR__"stoneroad2", 	  
          ]));
	set("coor/x",40);
  set("coor/y",280);
   set("coor/z",120);
   set("coor/x",40);
 set("coor/y",280);
   set("coor/z",120);
   setup();
}



