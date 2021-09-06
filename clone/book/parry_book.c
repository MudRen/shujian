// parry_book.c 

inherit ITEM;
inherit F_UNIQUE;
void create()
{
	set_name("��Ƥ", ({ "yang pi", "pi" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("unique", 1);
		set("long", "����һ����Ƥ������д��������������֣�������ѿ�(read)����\n");
		set("value", 2000);
		set("material", "paper");
		set("no_drop", "�������������뿪�㡣\n");
		set("treasure",1);
	}
}

void init()
{
	add_action("do_du", "read");
}
int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	int qklevel,neili_lost,lit, med;
	lit = me->query_skill("literate", 1);
	med = me->query_skill("medicine", 1);
	qklevel = me->query_skill("qiankun-danuoyi", 1);

	if (!(arg=="yang pi" ||arg=="pi"))
		return 0;

	if(me->query("family/master_name") != "���޼�")
		return notify_fail("ֻ�н����״����Ӳſ�����ϰǬ����Ų���񹦣�\n"); 
	if(!me->query_temp("mj_jiaozhu")) 
		return notify_fail("û�н��������κ��˶�������������ϰǬ����Ų���񹦣�\n"); 
	if(where->query("pigging"))
		return notify_fail("�㻹��ר�Ĺ���ɣ�\n");               
	if(me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if(me->is_fighting()) 
		return notify_fail("���޷���ս����ר�������ж���֪��\n");     
	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n"); 
	if(!lit)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
	if(me->query_int() < (qklevel/10)+20)
		return notify_fail("���ͷ�Բ����ã����²�����ϰǬ����Ų���񹦡�\n");
	if(me->query("combat_exp") < 350000)
		return notify_fail("���ʵս���鲻�㣬������ϰǬ����Ų���񹦡�\n");
	if(me->query("max_neili") < 1200)
		return notify_fail("����������㣬������ϰǬ����Ų���񹦡�\n");
	if(me->query_skill("force") < 200)
		return notify_fail("����ڹ��ȼ����㣬������ϰǬ����Ų���񹦡�\n");        
	if(!me->query_skill("shenghuo-shengong",1) 
	&& !me->query_skill("jiuyang-shengong",1) 
	&& !me->query_skill("jiuyin-zhengong",1))
		return notify_fail("�㷢������ڹ�·�Ӻ�Ǭ����Ų���ߵ�·�Ӳ�ͬ��������ȥû�ж��ĺô���\n");
	if((int)me->query("jing") < 30)
		return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");        
	if(me->query_skill("qiankun-danuoyi",1) > (me->query_skill("force",1)+10))
		return notify_fail("��������ڹ��Ļ����������ٽ��и���һ�����ߡ�\n");
	if((int)me->query("neili") < neili_lost)
		return notify_fail("�������������޷�������ô������书��\n");
	if((int)me->query("combat_exp") < (int)qklevel*qklevel*qklevel/10)
		return notify_fail("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
	if(qklevel > 200)
		return notify_fail("����Ǭ����Ų�Ƶ��߲��ķ�ʱ������һ����һʮ�ž��ķ�û�����ɣ����û���ٳ��ˡ�\n");
	if(qklevel > 60 && qklevel > lit+50)
		return notify_fail("��Ķ���д�ֵȼ��������ϲ�����Ƥ�ϵ��֡�\n");
//	if(qklevel > 60 && qklevel > med+40)
//		return notify_fail("��ı�������ȼ���������ⲻ����Ƥ�ϵ��ֵ���˼��\n");

	switch(random(3)) {
		case 0: message("vision", me->name() + "��������͵�Ѫ�죬�������ȴ�����ࡣ\n", environment(me), me); break;
		case 1: message("vision", me->name() + "���Ϻ�Ȼ��죬��ͷ�������£����̼��\n", environment(me), me); break;
		case 2: message("vision", me->name() + "���Ϻ�Ȼ���࣬����΢������麮����\n", environment(me), me); break;
	}
        
	if(qklevel > 190) {
		neili_lost = 30;
		me->receive_damage("jing", 55);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵ��߲��ķ����ƺ��е��ĵá�\n");
		return 1;
	}
	if(qklevel > 180){
		neili_lost = 25;
		me->receive_damage("jing", 50);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵ������ķ����ƺ��е��ĵá�\n");
		return 1;
	}
	if(qklevel > 150){
		neili_lost = 20;
		me->receive_damage("jing", 45);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵ�����ķ����ƺ��е��ĵá�\n");
		return 1;
	}
	if(qklevel > 120){
		neili_lost = 15;
		me->receive_damage("jing", 40);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵ��Ĳ��ķ����ƺ��е��ĵá�\n");
		return 1;
	}
	if(qklevel > 90){
		neili_lost = 10;
		me->receive_damage("jing", 35);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵ������ķ����ƺ��е��ĵá�\n");
		return 1;
	}
	if(qklevel > 60){
		neili_lost = 6;
		me->receive_damage("jing", 30);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵڶ����ķ����ƺ��е��ĵá�\n");
		return 1;
	}
	else {
		neili_lost = 5;
		me->receive_damage("jing", 25);
		me->set("neili",(int)me->query("neili")-neili_lost);
		me->improve_skill("qiankun-danuoyi", lit/3+1);
		write("��������ϰǬ����Ų�Ƶĵ�һ���ķ����ƺ��е��ĵá�\n");
		return 1;
	}
}
