// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/jiuguan.c

inherit ROOM;

void create()
{
        set("short", "�ƹ�");
        set("long", @LONG
���ǳ����Ǿ��������һ��С�ƹݡ����Ӳ����Ǻܿ�������ˮ�ǳ�����
�������۵ģ����ʺϾ����������ͨ���գ�������ǲ����ϰ�ԭҲ�ǳ��е�
���񣬽��첻֪����˺ȵ���������������Ҳ�����ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"neijie1",
        ]));
        
        set("objects", ([
                __DIR__"npc/jglaoban" : 1,
        ]));
        
        set("incity",1);
	setup();
}