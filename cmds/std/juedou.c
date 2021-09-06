// juedou.c
// by tiantian@sj 2000.7.17

#include <ansi.h>

int main(object me, string arg)
{
	object obj;
	string callname, msg;

	if( !arg )
	 return notify_fail("�����˭������\n");

    if(me->query_temp("juedou")) return notify_fail("ͬʱ�������˾�������־������������ƽ��\n");
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("���ﲻ׼������\n");

	if(strsrch(file_name(environment(me)),"/d/wuguan/") >= 0 && !obj->query_condition("killer"))
		return notify_fail("����ڽ�ֹ������\n");
		
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if (me->query_temp("combat_yield"))
		return notify_fail("�����򲻻����أ�������˾�����\n");
	if (wiz_level(me) < wiz_level(obj))
		return notify_fail("�㲻�ܹ�����ʦ�ȼ�����ߵĶ��֡�\n");

	if( me->is_killing(obj) || obj->is_killing(me) )
		return notify_fail("�Է��Ѿ���ʼ�����ˣ��㻹��Ҫ��ô������ô��\n");
	if (obj == me) return notify_fail("�� suicide -f ָ���ȽϿ�Щ��\n");

	if (userp(obj) && me->query_condition("killer") > 100)
		return notify_fail("һ�ղ���������ɱ����ˡ�\n");
/*
	if ( userp(me) && userp(obj) && obj->query("age") < 17 )
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");

	if ( userp(me) && userp(obj) && obj->query("combat_exp") < 15000 )
		return notify_fail("����ĳ�̫����, �����޸���֮�������Ҳ�µ����֡�\n");
*/
	callname = RANK_D->query_rude(obj);

if( !userp(obj) ) return notify_fail("���ܶ������˼ô�������񫣬���������ȥ�ɡ�\n");
    if( obj->query("race")!="����" )
	return notify_fail("����ô��������������ҧô��\n" );
	
    if( obj->query_temp("juedou") && obj->query_temp("juedou")!= me)
	return notify_fail("�Է��������˾����أ�������Ϣһ��ɡ�\n");

    if( obj->query_temp("juedou") && obj->query_temp("juedou")==me ) {
    message_vision("$N����ض�$nƲ��Ʋ�죺�����첻�����������������Ҳ��֪������ү��ֻ�ۡ�\n", me, obj );
    me->delete_temp("jiudou");
    obj->delete_temp("juedou");
	CHANNEL_D->do_channel(this_object(), "rumor", me->name(1)+"��" 
	    + obj->name(1)+"��"+environment(me)->query("short")
	    + "��ʼ����������");
    call_out("begin",3+random(5),me,obj);
return 1;
}
    msg = "$N����$n���һ������" + callname + "���ҽ�����㲻�����ݣ����ɣ�����ƽƽ�Ĵ���һ�ܰɡ���\n";
    message_vision(msg,me,obj);
    tell_object(obj, me->query("name")+"Ҫ���������������������ܶԷ������룬������Է�ʹ��juedou���\n");
    me->set_temp("juedou", obj);

    call_out("remove_effect",30,me);

	return 1;
}

void begin( object me, object obj )
{
	string mid, oid;

	if(!me || !obj ) return;
	if( environment(me)!=environment(obj) ) return;
	if( environment(me)->query("no_fight") || me->query_condition("killer") || obj->query_condition("killer") )
		return;
	mid = me->query("id");
	oid = obj->query("id");
	me->delete("last_death_time/"+oid);
	obj->delete("last_death_time/"+mid);
	me->kill_ob(obj);
	obj->kill_ob(me);
	me->delete_temp("kill_other/"+oid);
	obj->delete_temp("kill_other/"+mid);
	me->set_temp("other_kill/"+oid, 1);
	obj->set_temp("other_kill/"+mid, 1);
	me->set_temp("guarding", 1);
	obj->set_temp("guarding", 1);
}

void remove_effect( object me )
{
    if(!me) return;
    if(me->query_temp("juedou")) {
	tell_object(me,HIR"�Է��ܾ�����ľ�������\n"NOR );
	me->delete_temp("juedou");
    }
}

int help(object me)
{
  write(@HELP
ָ���ʽ��juedou <����>

���ָ������������Է��������ݵ�����������Է��������
�������󣬲�����һ����ʱ���ڣ�����Ҳʹ����ͬ
��ָ���ô˫��������һ��ʱ��󣬿�ʼ������ͼɱ��
�Է���

������˫����Ը�ķ�ʽ���Է����Բ�������ľ������󣬶�ѡ��������
��ʽ�˽�˫���Ķ�Թ��

�������ָ�kill fight ansuan
 
HELP
    );
    return 1;
}
