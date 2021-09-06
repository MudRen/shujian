// by ����Ӣ��

#include <ansi.h>
#include <dbase.h>
inherit ITEM;

void create()
{
	string name="", id="";

	name = HIC"���Ż�"NOR;
	id = "sizhangji";

	set_name(HIW"��"+name+HIW"������"NOR, ({ id+"'s yuepu", id, "yue pu", "yuepu" }));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2500);
		set("material", "paper");
		set("check", 1);
		set("music_name", name);
		set("music_id", id);
		set("music_add", 5);
		set("long", HIY"һ�����ף������ˡ�"+name+HIY"���ĵ��෽���������Щ�������ȡ�\n"+
			"������ж���Read���������������������ȡ�\n"NOR);
	}
}

void init()
{
	int i=0;
	string str="";

	if( environment() == this_player() ) {
		add_action("do_du", "read");
		if( query("check") > 0 ) {
			switch( random(4) ) {
				case  0: { i = random(3) + 2;str = HIW"Щ��"NOR;break; }
				case  1: { i = random(3) + 4;str = HIG"һЩ"NOR;break; }
				case  2: { i = random(3) + 6;str = HIR"���"NOR;break; }
				case  3: { i = random(3) + 8;str = RED"����"NOR;break; }
				default: { i = random(4) + 4;str = HIG"һЩ"NOR;       }
			}
			delete("check");
			set("music_add", i);
			set("long", HIY"һ�����ף������ˡ�"+query("music_name")+HIY"���ĵ��෽���������"+str+HIY"�����ȡ�\n"+
				"������ж���Read���������������������ȡ�\n"NOR);
		}
	}
}

int do_du(string arg)
{
	object me,ob;
	int i, j=0;

	me = this_player();
	ob = this_object(); 

	i = me->query_skill("string", 1);
	if( me->query_skill("flute", 1) > i ) i = me->query_skill("flute", 1);

	if( !(arg == ob->query("id") || arg == "yuepu") ) return 0;

	if( !me->query_skill("literate", 1) )
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");	   

	if( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() ) 
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if( !id(arg) )
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->query_skill("literate", 1) < 100 )
		return notify_fail("��Ķ���д�ֵȼ��������޷���������м��ص����ݡ�\n"); 

	if( i < ( j = call_other("/d/music/book/" + ob->query("music_id") + ".c", "query_level") ) )
		return notify_fail("�����������Ϊ��ȥ�ж����������ף�ʵ������Ϊ�����ˡ�\n");

	if( i < ob->query("music_add")*10 )
		return notify_fail("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫���ˣ�û��ѧ���κζ�����\n");

// ��������
	me->add("music/"+ob->query("music_id"), ob->query("music_add")); 
// ͳ��ʱ��
	me->set("music_time/"+ob->query("music_id"), time() );

	message("vision", me->name() + "�ó�һ��" + ob->name() + "������ж��š�\n", environment(me), me);
	write(HIC"���ж���" + ob->name() + HIC"�������Լ�����һ���µ�����������һ�㡣\n"YEL+ob->name()+YEL
		"��Ϊ�����еļ������������ˡ�\n");

	if( wizardp(me) ) tell_object(me, "����"+ob->query("music_id")+"���ӣ�"+ob->query("music_add")+"\n");
   	destruct(ob);
	return 1;
}
