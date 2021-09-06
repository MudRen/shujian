#include <ansi.h>

inherit ITEM;


void create()
{
	set("unit","��");
	set("no_get", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_give", 1);      
	set("material", "bamboo");
	set_weight(50);
	setup();
}

void init()
{
	object me = this_player();

	set_name (HIR "�������" NOR, ({ "lingpai","ling","pai" }));

	set("long", HIR "����������ݹ���������������������Աȥ�������ɰ�ʦ����(here XXX)��\n" NOR);

	if (me && present(this_object(), me)) {
		add_action("do_here", "here");
	}
}

int do_here(string str)
{
	object me = this_player(), ob = this_object();
	object ob1, ob2;
	object ob3;
	int exp,pot,shen;
        
	if (!str || str=="")
		return notify_fail ("���˭���ģ�\n");

	if (!ob1 = find_living(str))
		ob1 = LOGIN_D->find_body(str);
	if (ob1 == me) 
		return notify_fail("���Լ����ģ�\n");
	if(!objectp(ob2 = present(str, environment(me))) )
		return notify_fail("����û " + str + " ����ˡ�\n");

	if( !living(ob2) ) 
		return notify_fail("���" + ob1->name() + "������˵�ɡ�\n");            

	if (!userp(ob2) ) 
		return notify_fail("��ֻ�ܸ���Ҵ�·��\n");

	if( !ob2->query_temp("wg_go"))
		return notify_fail( "�Է���û�����˴�·��\n" );

	if( ob2->query_temp( "wg_road" ) == 1)
		return notify_fail( "��֪���Է�Ҫȥ��������\n" );
        
	if( !me->query_temp( "wg_lead" ) )
		return notify_fail( "��ô��ŵ���\n" );

	if( !objectp( ob3 = present( me->query_temp( "wg_goto" ), environment( me ) ) ) )
		return notify_fail( "������͵��ط�����\n" );
        
	message_vision( sprintf(HIC "$N��" + ob3->query( "name" )
		+ "˵����������������ݹ���ί�У�����λ" + RANK_D->query_respect( ob2 )
		+ "ǰ��" + RANK_D->query_respect( ob3 ) + "������ǹ������\n" NOR), me );
	message_vision( sprintf( HIC "" + ob3->query( "name" )
		+ "����ǰȥ��������ס$N��˫�֣�������˵����������\n"  NOR), ob2 );

	message_vision( sprintf( HIW "$N�ݸ�" + ob3->query("name")
		+ "һ��������ơ�\n" NOR), me );
        
	exp = 100 + random( 100 ) + random( me->query( "combat_exp" ) / 30000 ) ;
	if( exp > 250 )
		exp = 200 + random( 50 );
	pot = 50 + random( 50 ) + random( me->query( "combat_exp" ) / 60000 ) ;
	shen = 200 + random( 2 * exp );
	write( sprintf(HIW "�ã���������ˣ���õ���" + CHINESE_D->chinese_number( exp )+ "��ʵս�����" 
		+ CHINESE_D->chinese_number( shen ) + "������\n" NOR));

	me->add( "combat_exp", exp );
	me->add( "shen", shen );

	log_file("job/newbie", sprintf("%8s%-10s��·%8s%-10s���õ�%3d�㾭�飬�־���%d��\n",
		me->query("name"), "("+me->query("id")+")",
		ob1->query("name"), "("+ob1->query("id")+")", exp, me->query("combat_exp") ), me );

	me->delete_temp( "wg_lead" );
	me->delete_temp( "wg_goto" );
	ob1->delete_temp( "wg_go" );
	ob1->set("wg_help_exp", ob1->query("combat_exp") );
	destruct( ob );
	return 1;
}
