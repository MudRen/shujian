// Write By Yanyang@SJ 2001.10.3
// Room: /d/changan/baishulin1.c

inherit ROOM;
#include <room.h>

void create()
{
        set("short", "������");
        set("long", @LONG
����һƬ�����деİ����֡�Ũ�ܿ�����Ҷ�ڱ��������ǳ���ʹ�˷ֲ�
����ҹ����������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮�����ߵ������Ŭ
���ı��������ܵķ���Ѱ�ҳ�ȥ��·��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east"   : __DIR__"baishulin1",
                "west"   : __DIR__"baishulin1",
              "southeast": __DIR__"baishulin1",
              "southwest": __DIR__"baishulin1",
                "north"  : __DIR__"baishulin1",
        ]));

        set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        me->add_temp("ca_bsl",1);
  
        if( dir =="east") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"shihuangling");
                me->delete_temp("ca_bsl");
                return notify_fail("��ת��תȥ����ǰ���ڿ����������ˡ�\n");
                }
        }
        if( dir =="west") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"beilin");
                me->delete_temp("ca_bsl");
                return notify_fail("��ת��תȥ����ǰ���ڿ����������ˡ�\n");
                }
        }
        if( dir =="southeast") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"baishulin2");
                me->delete_temp("ca_bsl");
                return notify_fail("��ת��תȥ��������ǰ��Ȼ��һƬ�������������\n");
                }
        }
        if( dir =="southwest") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"changjie2");
                me->delete_temp("ca_bsl");
                return notify_fail("��ת��תȥ����ǰ���ڿ����������ˡ�\n");
                }
        }
        if( dir =="north") {
        if( me->query_temp("ca_bsl") > 20 + random(10) ) {
                me->move(__DIR__"xiaoyanta1");
                me->delete_temp("ca_bsl");
                return notify_fail("��ת��תȥ����ǰ���ڿ����������ˡ�\n");
                }
        }
        return ::valid_leave(me,dir);
}