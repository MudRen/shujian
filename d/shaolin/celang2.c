//celang2.c

inherit ROOM;

void create()
{
set("short", "����");
set("long", @LONG
�������������ȡ�����������������Ҳ�ò�������˸��ַ����ͼ�Σ�
���������ֱʣ��˵�׳��������������һƬ�����֣����ﻨ��������������
�Ŀ�������������ɮ������Ϣ�õ�ɮ�ᡣ   
LONG
	);
	set("exits", ([
		       "northeast" : __DIR__ "songshu3",
                       "south" : __DIR__ "stoneroad3",
                       "east" : __DIR__ "sengshe1",   
                      ]));
	set("coor/x",60);
  set("coor/y",280);
   set("coor/z",110);
   setup();
}



