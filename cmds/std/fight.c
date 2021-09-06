// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;
        string msg;

	if( environment(me)->query("no_fight") )
		return notify_fail("�����ֹս����\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("���빥��˭��\n");

	if( !obj->is_character() )
		return notify_fail("�����һ�㣬�ǲ��������\n");

	if( obj->is_fighting(me) )
		return notify_fail("���ͣ����ͣ����ͣ�\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "�Ѿ��޷�ս���ˡ�\n"); 

	if ( obj->query("job_npc"))
		return notify_fail(obj->name()+"������ûʲô��Ȥ����ս����\n");

	if(obj==me) return notify_fail("�㲻�ܹ����Լ���\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me ) {
		if(me->query("combat_exp") > obj->query("combat_exp")*2){
			if(me->query("shen") < -10000)
		                msg = "\n$N����$nһƳ��"+RANK_D->query_self_rude(me)+"���㻹��������ô����������ˣ�������ԣ�\n\n";
		        else msg = "\n$N����$n���˿���"+RANK_D->query_respect(obj)+"���������ֲ�������������ָ��ָ���㼸����ô����\n\n";
		        }
		else if(obj->query("combat_exp") > me->query("combat_exp")*2){
			if(me->query("shen") < -10000)
		                msg = "\n$N����$nһ��ȭ��"+RANK_D->query_respect(obj)+"��"+RANK_D->query_self(me)+"�ⲻ���۵�ׯ�ڰ�ʽ����ָ�㼸����Σ�\n\n";
		        else msg = "\n$N����$n����һ�ϵ���"+RANK_D->query_self(me)+me->name()+"���ڴ˿���"+obj->name()+RANK_D->query_close(obj, me)+"�ͽ̣�\n\n";
		        }
		else {
			if(me->query("shen") < -10000)
		                msg = "\n$N����$n����һЦ��������˵"+RANK_D->query_respect(obj)+"���ո�ǿ��"+RANK_D->query_self_rude(me)+"���ڴ���̼�ʽ���У���Σ�\n\n";
		        else msg = "\n$N����$n˵����" + RANK_D->query_self(me) + me->name() + "�����"+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n";
		        }
		message_vision(msg, me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL "�����Ը��ͶԷ��������գ�����Ҳ��" + me->name() + "��һ�� fight ָ�\n" NOR);
		write(YEL "���ڶԷ�������ҿ��Ƶ���������ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
		return 1;
	}

	({ me, obj })->delete_temp("guarding");
	if( obj->query("can_speak") ) {
		if(me->query("combat_exp") > obj->query("combat_exp")*2 && userp(obj)){
			if(me->query("shen") < -10000)
		                msg = "\n$Nһ����Ц���ðɣ�������"+RANK_D->query_rude(obj)+"�������������ҽ�ѵ��ѵ��ɣ�\n\n";
		        else msg = "\n$N���Ǻǡ�һЦ����Ȼ"+RANK_D->query_respect(obj)+"��̣���������ָ��ָ���㼸�аɣ�\n\n";
		        }
		else if(obj->query("combat_exp") > me->query("combat_exp")*2 && userp(obj)){
			if(me->query("shen") < -10000)
		                msg = "\n$N��Цһ������Ӵ��"+RANK_D->query_respect(obj)+"����ô������"+RANK_D->query_self(me)+"����ֻ���ڴ����׳��ˣ�\n\n";
		        else msg = "\n$N��Ȼ�𾴣�����"+RANK_D->query_respect(obj)+"������"+RANK_D->query_self(me)+"����ֻ�ù�������������ˣ�\n\n";
		        }
		else {
			if(me->query("shen") < -10000)
		                msg = "\n$N����$n�ٺ�һЦ��������������"+RANK_D->query_self_rude(me)+"��������"+RANK_D->query_respect(obj)+"�ĸ��аɣ�\n\n";
		        else msg = "\n$N����$n˵����" + RANK_D->query_self(me) + me->name() + "�����"+ RANK_D->query_respect(obj) + "�ĸ��У�\n\n";
		}
		obj->delete_temp("pending/fight");
        message_vision(CYN + msg + NOR, me, obj);

		notify_fail("������" + obj->name() + "��������������\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N���һ������ʼ��$n����������\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : fight <����>
 
���ָ��������һ������ֽ̡������ǡ��д����ա���������ʽ��ս��������
�㵽Ϊֹ�����ֻ����������������������ˣ����ǲ��������е�  NPC ��ϲ��
��ܣ���������״����ı���Ҫ��ᱻ�ܾ���
 
�������ָ��: kill

PS. ����Է���Ը����������ս������Ȼ���������� kill ָ�ʼս������
    �� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 
