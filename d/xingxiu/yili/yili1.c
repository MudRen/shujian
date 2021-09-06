// Room: /d/xingxiu/yili1.c
// by snowman@SJ
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "�ϳ���");
	set("long", @LONG
����������Զ����ͨ��˹���ϵ����ã��������ء�������������������ͨ
��Ҫ�壬�Ǻ�ᶫ����˿��֮·��ʮ����Ҫ�ĵ�����������������ڰ�������
����Ͻ�����������ƽ̹������ӱ����ȵض������Ǹ�һ���ģ�������Ҫ����
ǽ����������̨��ǹ�ۣ��䱸ɭ�ϡ�
LONG
        );
        set("outdoors", "����");
        set("exits", ([
                "south" : __DIR__"yilihe",
                "north" : __DIR__"yili2",
        ]));

        set("objects", ([
                __DIR__"../npc/bing" : 2,
                __DIR__"../npc/shangren" : 1,
        ]));
	setup();
	quarter_pass();
}

void quarter_pass()
{
        string local;

        local = NATURE_D->query_daytime();

        switch(local){
            case "event_night":
            case "event_midnight":
                  set("long", @LONG
����������Զ����ͨ��˹���ϵ����ã��������ء�������������������ͨ
��Ҫ�壬�Ǻ�ᶫ����˿��֮·��ʮ����Ҫ�ĵ�����������������ڰ�������
����Ͻ�����������ƽ̹������ӱ����ȵض������Ǹ�һ���ģ�������Ҫ����
ǽ����������̨��ǹ�ۣ��䱸ɭ�ϡ�������ҹ�䣬�����ѹأ�ֻ�м�������ʿ
���ڳ��ſ���ҹ��
LONG);
        	  delete("exits/north");
                  break;
            default: set("long", @LONG
����������Զ����ͨ��˹���ϵ����ã��������ء�������������������ͨ
��Ҫ�壬�Ǻ�ᶫ����˿��֮·��ʮ����Ҫ�ĵ�����������������ڰ�������
����Ͻ�����������ƽ̹������ӱ����ȵض������Ǹ�һ���ģ�������Ҫ����
ǽ����������̨��ǹ�ۣ��䱸ɭ�ϡ�
LONG);
                  set("exits/north", __DIR__"yili2");
        	  break;
        }
        call_out("quarter_pass", 60);
}
