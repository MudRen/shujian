// Room: /d/huashan/jinshe/obj/jinshemiji.c
// Date: Look 99/03/25

inherit ITEM;

void create()
{
	set_name("�����ؼ�", ({ "jinshe miji", "jinshe","miji" }));
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ�������ɾ���ѩ�˵���ѧ�ؼ�������д�����������С�֡�\n");
		set("material", "paper");
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
		set("no_give", 1);
		set("no_put", 1);
		set("unique", 1);
		set("treasure", 1);
	}
}

void init()
{
	add_action("do_du", "read");
}

int do_du(string arg)
{
	object me = this_player();
	int jlevel; 
	//int zlevel;
	int neili_lost;

	if (!(arg=="jianfa" || arg=="zhangfa"))
		return 0;

	if (arg=="jianfa"){       
		if (me->is_busy()) {
			write("��������æ���ء�\n");
			return 1;
		}
		if( me->is_fighting() ) {
			write("�������ս���з����ж��ؼ���\n");
			return 1;
		}
		if( !me->query_skill("literate", 1) ){
			write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
			return 1;
		}
                if (me->query("str") >20 && me->query("str") <31 ){
			write("����������̫�ߣ��޷�������߽�����Ҫ�졣\n");
			return 1;
		}
		if( (int)me->query("jing") < 30 ) {
			write("��̫ƣ���ˣ��޷��ж���ѧ�ؼ���\n");
			return 1;
		}
		if (me->query_skill("sword",1)<30){
			write("��Ļ�����û�д�ã�����ѧϰ���߽�����\n");
			return 1;
		}
		if( (int)me->query("neili") < neili_lost) {
			write("�������������޷�������ô������书��\n");
			return 1;
		}
		jlevel = me->query_skill("jinshe-jianfa", 1);
		if( (int)me->query("combat_exp") < (int)jlevel*jlevel*jlevel/10 ) {
			write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
			return 1;
		}
		if( me->query_skill("jinshe-jianfa", 1) >= 101){
			write("���Ѿ��޷��ٴ��ؼ���ѧ��ʲô��Ҫ����ߵ���Ϊ�����������ˡ�\n");
			return 1;
		}
		neili_lost=(int)(me->query_skill("jinshe-jianfa",1)/15);
		me->receive_damage("jing", 20);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("jinshe-jianfa", (int)me->query_skill("literate", 1)/3+1);
		if( ! me->query("jinshe/jianfa"))
			me->set("jinshe/jianfa", 1);
		message("vision", me->name() + "����һ���ؼ������ж���\n", environment(me), me);
		write("���ж������߽������������ĵá�\n");
		return 1;
	}
/*
	if (arg=="zhangfa") {
		if (me->is_busy()) {
			write("��������æ���ء�\n");
			return 1;
		}
		if( me->is_fighting() ) {
			write("�������ս���з����ж��ؼ���\n");
			return 1;
		}
		if (me->query("str") >20 ){
			write("����������̫�ߣ��޷���������Ʒ���Ҫ�졣\n");
			return 1;
		}
		if( !me->query_skill("literate", 1) ){
			write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
			return 1;
		}
		if( (int)me->query("jing") < 20 ) {
			write("��̫ƣ���ˣ��޷��ж���ѧ�ؼ���\n");
			return 1;
		}
		if (me->query_skill("strike",1)<30){
			write("��Ļ���û�д�ã������ж������ؼ���\n");
			return 1;
		}
		if( (int)me->query("neili") < neili_lost) {
			write("�������������޷��ж���ô������书��\n");
			return 1;
		}
		zlevel = me->query_skill("jinshe-zhangfa", 1);
		if( (int)me->query("combat_exp") < (int)zlevel*zlevel*zlevel/10 ) {
			write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
			return 1;
		}
		if( me->query_skill("jinshe-zhangfa", 1) >= 101){
			write("���Ѿ��޷��ٴ��ؼ���ѧ��ʲô��Ҫ����ߵ���Ϊ�����������ˡ�\n");
			return 1;
		}
		neili_lost=(int)(me->query_skill("jinshe-zhangfa",1)/15);
		me->receive_damage("jing", 20);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("jinshe-zhangfa", (int)me->query_skill("literate", 1)/3+1);
		if( ! me->query("jinshe/zhangfa"))
			me->set("jinshe/zhangfa", 1);
		message("vision", me->name() + "����һ���ؼ������ж���\n", environment(me), me);
		write("���ж������������ơ��������ĵá�\n");
		return 1;
	}
*/
}
