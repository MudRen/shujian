// Room: /u/jpei/thd/shore.c
// ����ת��ʦ���Ĵ��� Modified by Numa
// YUJ 2001-10-29

#include <ansi.h>
inherit ROOM;
int prevent_get();
void create()
{
	set("short", "����");
	set("long", @LONG
���ɻ�ؿ������ܣ���������һ���ô�����ܳ������ҵĽ�ʯ�⣬ʲô��
û�С������濴��һ��Сɽ����������,����ͨ�������ұڵ���ɽ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northup" : __DIR__"hill",
	]) );
	set("outdoors","�һ���");

	setup();
}

void init()
{
	object me = this_player();

	if (me->query("family/family_name")=="�һ���")
	{
		if ((int)me->query("family/generation")==2)
		{
			if ((int)me->query_skill("bihai-chaosheng",1) < 130 && me->query_skill("bihai-chaosheng",1) >= 80)
			{
				me->set("family/master_id","lu chengfeng");
				me->set("family/master_name","½�˷�");
				me->set("family/generation",3);
				me->set("title","�һ�������������");
				write( HIY "�������ı̺������ȼ�С��һ����ʮ����ϵͳ�ѽ���ת��Ϊ�һ������������ӡ�\n" NOR);
				return;
			}
			else if ((int)me->query_skill("bihai-chaosheng",1) < 80)
			{
				me->set("family/master_id","lu guanying");
				me->set("family/master_name","½��Ӣ");
				me->set("family/generation",4);
				me->set("title","�һ������Ĵ�����");
				write( HIY "�������ı̺������ȼ�С�ڰ�ʮ����ϵͳ�ѽ���ת��Ϊ�һ������Ĵ����ӡ�\n" NOR);
				return;
			}
		}
		else if ((int)me->query("family/generation")==3)
		{
			if ((int)me->query_skill("bihai-chaosheng",1) < 80)
			{
				me->set("family/master_id","lu guanying");
				me->set("family/master_name","½��Ӣ");
				me->set("family/generation",4);
				me->set("title","�һ������Ĵ�����");
				write( HIY "�������ı̺������ȼ�С�ڰ�ʮ����ϵͳ�ѽ���ת��Ϊ�һ������Ĵ����ӡ�\n" NOR);
				return;
			}
		}
	}
}
