inherit ROOM;

void create()
{
        set("short", "�ɿ�");
        set("long", @LONG
��ǰ���������ޱߵ�ãã�󺣣���ˮ���������һ�˽���һ�˵س����߻�
����һ����ȥ��ֻ������Ÿ�ں����Ϸ��裬ż��Ҳ�ɼ���Զ���з�Ӱ�ӹ���
������������Ψһ����ͣ�������ĵط�������Ķ������߶���ɳ̲����������
һ�����֡�
LONG
        );

        set("exits", ([
"northeast" : __DIR__"sande",
 "northwest" : __DIR__"sandw",
"north" : __DIR__"trees1",
        ]));
		  set("objects", ([
   __DIR__"npc/chuanfu" :1,
	]));
	set("no_fight",1);
        set("outdoors", "������");
        set("coor/x",490);
  set("coor/y",420);
   set("coor/z",0);
   setup();
        
}

