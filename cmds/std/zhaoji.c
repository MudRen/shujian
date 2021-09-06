// zhaoji.c �� ������ϵͳ����
// by lane@SJ 1/10/2005

#include <ansi.h>

inherit F_CLEAN_UP;
int help(object);

int main(object me)
{
	object obj, *enemy;
	string fam, fire;
	int i;

	fam = me->query("family/family_name");

	if( me->is_busy() )
		return notify_fail("����æ���أ���Ъ�����ɡ�\n");

	if( !fam )
		return notify_fail("�����ټ���å���£�\n");

	if( !me->query_temp("inherit_master") )
		return notify_fail("������С��ɫ��ƾʲô��"+fam+"�з���ʩ���\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ��ս������ͻ����ط������°ɣ�\n");

	if( !me->is_fighting() )
		return notify_fail("ûʲô���¾ͱ��ټ��˰ɣ�����������ȥҲ���۵ģ�\n");

	enemy = me->query_enemy();
	i = sizeof(enemy);
	while (i--) {
		if( enemy[i]->is_killing(me->query("id")) ) break;
		if( me->is_killing(enemy[i]->query("id")) ) break;
	}
	if (i < 0)
		return notify_fail("�ͱ����д����գ�û��Ҫ��ô��ʦ���ڰɣ�\n");

	if( me->query_temp("zhaoji_start") )
		return notify_fail("���Ѿ��ų����ټ�ͬ�ŵ�Ѷ�ţ����ĵȵȴ��ɣ�\n");

	obj = me->query_temp("zhaoji_npc");

	if( obj && environment(me) == environment(obj) ) {
		message_vision(CYN"$N��$n����һ������Ϭ��ͨ��΢Ц���\n"NOR, me, obj);
		me->start_busy(1);
			return 1;
	}

	switch( random(6) ) {
		case 0:fire = YEL"����"NOR; break;
		case 1:fire = RED"����"NOR; break;
		case 2:fire = HIG"����"NOR; break;
		case 3:fire = BLU"����"NOR; break;
		case 4:fire = WHT"����"NOR; break;
		case 5:fire = MAG"����"NOR; break;
	}
	switch( random(5) ) {
		case 0:message_vision(HIM"\n$NͻȻ��Ծ���𣬽�����"+ chinese_number(1+random(3)) +"ֻ�׸��$N��������𣬳����ƶˡ�\n\n"NOR, me); break;
		case 1:message_vision(HIW"\n$N�͵��������˫��һ�У�"+ chinese_number(1+random(3)) +"ֻ�׸�������ֱ��������\n\n"NOR, me); break;
		case 2:message_vision(HIR"\n$N��Ȼ����Ȧ�⣬������ͳ�һ�����񣬽�����"+ chinese_number(1+random(3)) +"��"+fire+HIR"ֱ��������\n\n"NOR, me); break;
		case 3:message_vision(HIY"\n$NͻȻ�Ĵ�����ͳ�һ�����񣬽�����"+ chinese_number(1+random(3)) +"��"+fire+HIY"��������\n\n"NOR, me); break;
		case 4:message_vision(HIC"\n$N��Ȼ�������У����˽��к������ų�����ͬ�ŵ�Ѷ�ţ�ֻ��"+ chinese_number(1+random(3)) +"��"+fire+HIC"��������\n\n"NOR, me); break;
	}
	me->set_temp("zhaoji_start", 1);
	me->start_busy(1+random(2));
	call_out("start", random(4)+1, me);
	return 1;
}

void start(object me)
{
	object obj;

	if( !me ) return;

	if( !me->is_fighting() ) {
		me->delete_temp("zhaoji_start");
		return;
	}

	if( !me->query_temp("inherit_master") ) {
		me->delete_temp("zhaoji_start");
		return;
	}

	me->delete_temp("zhaoji_start");
	obj = new("/clone/npc/party_npc");

	if( !obj ) {
		write(HIW"\n���ã���˵������ɱ����˼����ˣ���Ͽ�֪ͨ��ʦ�� Party Npc cannot go to here...\n\n"NOR);
		return;
	}

	obj->move(environment(me));
	me->set_temp("zhaoji_npc", obj);
	obj->set_master_player(me);

	switch( random(4) ) {
		case 0:message_vision(CYN"\nԶ����ͻȻ����һ����Х��һ��$nʩչ�Ṧ�ɳ۶�����\n"NOR, me, obj); break;
		case 1:message_vision(CYN"\nֻ��Զ���ҴҸ���һ��$n��\n"NOR, me, obj); break;
		case 2:message_vision(CYN"\nһ��$n������$N��Ѷ�ţ��Ҵ�ææ���˹�����\n"NOR, me, obj); break;
		case 3:message_vision(CYN"\nͻȻ��Զ��С·������һ��$n�������ܵ����ǰ��\n"NOR, me, obj); break;
	}
	message_vision(HIW"$nһ����ʽ�پ�������һ������������Σ�գ��������㡭����\n"NOR, me, obj);
	return;
}

int help(object me)
{
	write(@HELP

���ָ�������ټ����ɵ��Ӱ�����һ��ս������Ȼ������������������ŵ�
������ɵ��ӻ���º���ս�������������ҳ��⣩��

HELP);
	return 1;
}
