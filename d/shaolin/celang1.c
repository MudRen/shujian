//celang1.c

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
		       "northwest" : __DIR__ "huaishu2",
                        "south" : __DIR__ "stoneroad4", 
                        "west" : __DIR__ "sengshe4", 
                      ]));
	set("coor/x",40);
  set("coor/y",290);
   set("coor/z",120);
   set("coor/x",40);
 set("coor/y",290);
   set("coor/z",120);
   setup();
}



