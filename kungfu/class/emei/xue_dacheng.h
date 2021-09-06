// quest for force dacheng-fofa linji-zhuang
// Lklv 2001.10.18 update

#include <ansi.h>

int ask_force()
{
        command("say ��������ϰ�ڹ�֮��������֪����������ʦү����������ţ��ʯ�������ڹ���\n");
        return 1;
}

int ask_fofa()
{
	object me = this_player();
	switch(random(4)) {
	case 0: {
		command("say ��Ȼ�����Ҵ�˷𷨣����ȸ��㽲����������
		��к�����ס�ڶ���ɽ��
		�и�ɮ��������ʲô��ʤ�壿�����˵��ֱ����ᰡ�
		ɮ�����ʣ������£�������֮�£���Σ����������������塣
		ɮ�����ʣ�ʲô�Ƿ𷨣�������˵��������ǰ���˹ġ�
		��ɮ˵�����Ҳ���������к����������ش������أ�\n");
		me->set_temp("ask_force_1", 1);
		call_out("do_nod1", 5, me); return 1; } break;

	case 1: {
		command("say ��Ȼ�����Ҵ�˷𷨣����ȸ��㽲����������
		��ӡ�������ڻ����¿�����
		��ӡ������һ�������ɮԲ��ʲô�ǹŷ�δ�ң�
		Բ��˵��ͥǰ�����ӡ���ӡ����������˵��ʲô��\n");
		me->set_temp("ask_force_2", 1);
		call_out("do_nod2", 5, me); return 1; } break;

	case 2: {
		command("say ��Ȼ�����Ҵ�˷𷨣����ȸ��㽲����������
		�޺�������ס�ڶ���ɽ�Ӹ�Ժ�
		��ɮ��������ʲô���������⣿����˵�����к��棬���︡Ž��
		ɮ���ʣ�����ô��᣿���޺������������ش������أ�\n");
		me->set_temp("ask_force_3", 1);
		call_out("do_nod3", 5, me); return 1; } break;

	case 3: {
		command("say ��Ȼ�����Ҵ�˷𷨣����ȸ��㽲����������
		����������ڶ���ɽ���ҡ�
		������������죬�и�ɮ�˳����ʣ�ʲô�Ƿ𷨴��⣿
		�������˵���ճ���֪�����ʣ������ĵ��ǰ�ƣ�
		ɮ�����ʣ�ʲô��˫�徳������������������ش������أ�\n");
		me->set_temp("ask_force_4", 1);
		call_out("do_nod4", 5, me);
		return 1;
		}
	break;
	}
}

int ask_linji()
{
	command("say �ټ�ʮ��ׯһ����ʮ��ׯ��ÿ����һׯ���ж�������Ī��ô���
		�ر��ǵ���ʮ��ׯ��Ϊ�����ڻ��ͨʱ����������Ϊ�������棬��
		�����ӿ���ʹ�õ��ڹ����칦�ܡ�ϣ�����ܺúþ���������������
		�д�ɡ�\n");
	return 1;
}

int do_nod1(object me)
{
	if (this_player()) me = this_player();
	if (!me->query_temp("ask_force_1")) return 0;
	if (me->query("potential", 1) < 1) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if ((int)me->query("jing", 1) < ( 60 - (int)me->query("int") * 2 )) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		return 1;
	}
	if((int)me->query_skill("dacheng-fofa", 1) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121){
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if((int)me->query_skill("dacheng-fofa", 1) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121){
		if( random(10) > 3 ) {
			write(HIY"��������һ�������������������¡�
			��˵��������ǧ��ĺ��˰١�\n"NOR, me);
			me->improve_skill("dacheng-fofa", (int)me->query("int") * 4 );
			me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
			me->add("potential", - 1);
			me->delete_temp("ask_force_1", 1);
			return 1;
		}
		else {
			write("����ϸ���˰��죬Ҳ�벻������\n");
			me->receive_damage("jing", 25);
			me->delete_temp("ask_force_1");
			return 1;
		}
	}
}

int do_nod2(object me)
{
	if (this_player()) me = this_player();
	if (!me->query_temp("ask_force_2")) return 0;
	if ((int)me->query("jing", 1) < ( 60 - (int)me->query("int") * 2 )){
		write("����ϸ���˰��죬Ҳ�벻������\n");
		return 1;
	}
	if (me->query("potential", 1) < 1 ) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if ((int)me->query_skill("dacheng-fofa", 1) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121 ) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if((int)me->query_skill("dacheng-fofa", 1) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121 ) {
		if(random(10) > 3) {
			write(HIC"��������һ������������������ʡ�
			����������˵��һ��Ͷ�ھ��֡����ⲻ֪��ҲͶ��һ�Σ�\n"NOR, me);
			me->improve_skill("dacheng-fofa", (int)me->query("int") * 4 );
			me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
			me->add("potential", -1);
			me->delete_temp("ask_force_2", 1);
			return 1;
		}
		else {
			write("����ϸ���˰��죬Ҳ�벻������\n");
			me->receive_damage("jing", 25);
			me->delete_temp("ask_force_2");
			return 1;
		}
	}
}

int do_nod3(object me)
{
	if (this_player()) me = this_player();
	if (!me->query_temp("ask_force_3")) return 0;
	if ((int)me->query("jing", 1) < ( 60 - (int)me->query("int") * 2 )) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		return 1;
	}
	if (me->query("potential", 1) < 1 ) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if ((int)me->query_skill("dacheng-fofa", 1) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121 ) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if ((int)me->query_skill("dacheng-fofa", 1) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121 ) {
		if(random(10) >= 3 ) {
			write(HIR"��������һ����������������ʡ������ңָ��ɣ���Ǳߡ�\n"NOR, me);
			me->improve_skill("dacheng-fofa", (int)me->query("int") * 4 );
			me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
			me->add("potential", -1);
			me->delete_temp("ask_force_3", 1);
			return 1;
		}
		else {
			write("����ϸ���˰��죬Ҳ�벻������\n");
			me->receive_damage("jing", 25);
			me->delete_temp("ask_force_3");
			return 1;
		}
	}
}

int do_nod4(object me)
{
	if (this_player()) me = this_player();
	if (!me->query_temp("ask_force_4")) return 0;
	if ((int)me->query("jing", 1) < ( 60 - (int)me->query("int") * 2 )) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		return 1;
	}
	if (me->query("potential", 1) < 1 ) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if ((int)me->query_skill("dacheng-fofa", 1) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121 ) {
		write("����ϸ���˰��죬Ҳ�벻������\n");
		me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
		return 1;
	}
	if ((int)me->query_skill("dacheng-fofa", 1) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121 ) {
		if(random(10) > 3 ) {
			write(HIW"��������һ������������������ʡ�������ҹ��ˮ���ֺ�����������ǰɽ��\n"NOR, me);
			me->improve_skill("dacheng-fofa", (int)me->query("int") * 4 );
			me->receive_damage("jing", 80 - (int)me->query("int") * 2 );
			me->add("potential", -1);
			me->delete_temp("ask_force_4", 1);
			return 1;
		}
		else {
			write("����ϸ���˰��죬Ҳ�벻������\n");
			me->receive_damage("jing", 25);
			me->delete_temp("ask_force_4");
			return 1;
		}
	}
}
