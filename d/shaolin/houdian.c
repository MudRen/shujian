//houdian.c

inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
����ģ�������߶���ˮĥʯ�ڣ��ο��ŷ��Ÿ�λ���ʹ�µ�Ф��
�������������һ�ڴ�ˮ��(gang)���Լ�����ɮ������ڿʼ��ճ�����֮
�衣ÿ�ն���רְɮ�´���ǰ���ľ��е�ˮ���ˡ�
LONG 
);
        
        set("exits", ([
                     "west" : __DIR__ "hguangz4",
                     "east" : __DIR__ "hguangz5",
                     "north" : __DIR__ "taijie",
        ]));

        set("objects",([
          CLASS_D("shaolin") + "/hui-kong" : 1,
          __DIR__"npc/zjseng" : 1
         ]));

        set("item_desc", ([
        "gang" : "����һ��ͭ�ƵĴ�ף������ʢ�¼���Ͱˮ��\n",
	]));

//        set("resource/water",1); 
        set("coor/x",50);
  set("coor/y",340);
   set("coor/z",120);
   set("coor/x",50);
 set("coor/y",340);
   set("coor/z",120);
   setup();
}           
