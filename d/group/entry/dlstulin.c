// automake group room , Wed Aug  3 19:29:22 2011
inherit ROOM;
#include <ansi.h>
#include "/d/group/entry.h"
void create()
{
set("short","����");
set("long","һ̤�����֡���ǧ�˰�̬�����ͣ��ͷ·�ʹ�˽�����һ��������ء��е�
������׶�ƽ���ֱ���죻�е���������ʿ����װ�������е���������Ů������
Զ�����е����������Ӳݴ����������Ұ�����е�ɰʯ���ݣ���¶������
");
set("exits",([
"north":"/d/dali/dalisouth/dg1","west":"/d/dali/yideng/fanpu","southup":"/d/dali/dalisouth/xiushan","northwest":"/d/group/peace/1312370962.c",
]));
set("outdoors","�������");
set("group",1);
setup();
}
