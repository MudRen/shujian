// Lane@SJ 2005/3/27
// 2005/3/31 ���������Ʒ play Ч������Ʒ���Ϊ (music_treasure)

#include <ansi.h>;

inherit F_CLEAN_UP;

#define MUSIC_CHECK	"/cmds/usr/music"

int main(object me, string arg)
{
	string qin, name;
	object obj;
	int j, n;
	mapping msg;

	MUSIC_CHECK->check_music(me);

	if( !arg ) return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("�㻹��ר����ս�ɣ�\n");

	if( me->query("jingli") < 100 )
		return notify_fail("���ǵȵ������㹻������ʱ���ٵ��ɣ�\n");

	if( sscanf(arg, "%s %s", qin, name)!=2 )
		return notify_fail("��Ҫ��ʲô������\n");

	obj = present(qin, me);

	if( !obj ) return notify_fail("������ʲô������\n");

	if( obj->query("id") != "yao qin" && obj->query("id") != "pi pa" && obj->query("id") != "gu zheng" )
		return notify_fail( obj->name()+"���ⶫ�����������٣������ӳ������˰ɣ�\n");

	if( file_size("/d/music/book/"+name+".c") < 0 )
		return notify_fail( name+"������û���������ɣ�\n");

	if( me->query("music/"+name) == 0 ) {
		me->delete("music/"+name);
		return notify_fail("��Ϊ����ȱ����ϰ�����Ѿ������ˡ�"+call_other("/d/music/book/"+name+".c", "book_name")+"���ĵ��෽����\n");
	}

	if( !me->query("music/"+name) )
		return notify_fail("�����ڻ����ᵯ���������ӣ�\n");

	if( me->query("jingli") < ( j = call_other("/d/music/book/"+name+".c", "query_jingli") ) )
		return notify_fail("�����ڵľ��������������޷����������\n");

	if( me->query("neili") < ( n = call_other("/d/music/book/"+name+".c", "query_neili") ) )
		return notify_fail("�����ڵ����������������޷����������\n");

	if( me->query_skill("string", 1) < ( call_other("/d/music/book/"+name+".c", "query_level") ) )
		return notify_fail("��������ټ������������޷����������\n");

	if( me->query_condition("music_busy") > 1 )
                return notify_fail("������������������Ъ���ڵ���ɣ�\n");

	message_vision(HIW"$N��ϥ�������ó����ϵ�$n"HIW"����ʼ׼������"+call_other("/d/music/book/"+name+".c", "book_name")+HIW"��\n\n", me, obj);

	msg = call_other("/d/music/book/"+name+".c", "play_msg");

	if( !msg || undefinedp(msg["start_msg"]))
		message_vision(YEL"$N������ӽ̾�������ֹ��ȣ�����˿��ĸ����������ҡֱ�ϣ�һ�е���������֮��ȥ...........\n\n"NOR, me);

	else message_vision(msg["start_msg"], me, obj);

	me->apply_condition("music_busy", random(4) + 4 );
	me->add("jingli", -j );
	me->add("neili", -n );
	me->start_busy(6);

	if( obj->query("music_treasure") >= 1 )
		me->set_temp("music_treasure", 1);

	remove_call_out("end");
	call_out("end", 4 + random(2), me , name);	

	return 1;
}

int end(object me, string name)
{
	mapping msg;
	int i=0;

	if( !me ) return 0;

	if( !living(me) || me->is_ghost() ) return 0;

	msg = call_other("/d/music/book/"+name+".c", "play_msg");

	if( !msg || undefinedp(msg["end_msg"]) )
		message_vision(HIW"$Nһ�е������������ֵĽ�����ֹ...........\n\n"NOR, me);
	else message_vision(msg["end_msg"], me);
	me->start_busy(1);

	i = me->query_skill("string", 1);

	if( me->query_temp("music_treasure") >= 1 ) i += i/5;

	me->delete_temp("music_treasure");

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 1 ) {
		me->set("eff_qi", me->query("max_qi"));
		if( wizardp(me) ) tell_object(me, "Ч������ȫ�ָ���Ѫ��\n");
	}
	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 2 ) {
		me->set("eff_jing", me->query("max_jing"));
		if( wizardp(me) ) tell_object(me, "Ч������ȫ�ָ���Ѫ��\n");
	}
	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 3 ) {
		me->clear_conditions_by_type("poison");
		if( wizardp(me) ) tell_object(me, "Ч����������ڶ��ء�\n");
	}
	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 4 ) {
		me->add("neili", me->query("max_neili")/2 );
		me->add("jingli", me->query("eff_jingli")/2 );
		if( me->query("neili") > me->query("max_neili")*2 )
			me->set("neili", me->query("max_neili")*2 );
		if( me->query("jingli") > me->query("eff_jingli")*2 )
			me->set("jingli", me->query("eff_jingli")*2 );
		if( wizardp(me) ) tell_object(me, "Ч������������("+me->query("max_neili")/2+")����("+me->query("eff_jingli")/2+")��\n");
	}
	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 5 ) {
		if( !me->query_temp("music_parry") ) {
			me->add_temp("apply/parry", i/3);
			me->set_temp("music_parry", i/3);
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")���������м�("+i/3+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 6 ) {
		if( !me->query_temp("music_dodge") ) {
			me->add_temp("apply/dodge", i/3);
			me->set_temp("music_dodge", i/3);
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")���������Ṧ("+i/3+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 7 ) {
		if( !me->query_temp("music_damage") ) {
			me->add_temp("apply/damage", i/5);
			me->set_temp("music_damage", i/5);
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")������������("+i/5+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 8 ) {
		if( !me->query_temp("music_armor") ) {
			me->add_temp("apply/armor", i/4);
			me->set_temp("music_armor", i/4);
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")�������ӷ���("+i/4+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 9 ) {
		if( !me->query_temp("music_attack") ) {
			me->add_temp("apply/attack", i/4);
			me->set_temp("music_attack", i/4);
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")������������("+i/4+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 10 ) {
		if( !me->query_temp("music_strength") ) {
			me->add_temp("apply/strength", i/50+1 );
			me->set_temp("music_strength", i/50+1 );
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")�������ӱ���("+(i/50+1)+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 11 ) {
		if( !me->query_temp("music_dexerity") ) {
			me->add_temp("apply/dexerity", i/50+1 );
			me->set_temp("music_dexerity", i/50+1 );
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")����������("+(i/50+1)+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 12 ) {
		if( !me->query_temp("music_intelligence") ) {
			me->add_temp("apply/intelligence", i/50+1 );
			me->set_temp("music_intelligence", i/50+1 );
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")������������("+(i/50+1)+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 13 ) {
		if( !me->query_temp("music_constitution") ) {
			me->add_temp("apply/constitution", i/50+1 );
			me->set_temp("music_constitution", i/50+1 );
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")�������Ӹ���("+(i/50+1)+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	if( call_other("/d/music/book/"+name+".c", "query_purpose") == 14 ) {
		if( !me->query_temp("music_force") ) {
			me->add_temp("apply/force", i/2);
			me->set_temp("music_force", i/2);
			remove_call_out("remove_effect");
			call_out("remove_effect", 10, me, 30+i/10);
			if( wizardp(me) ) tell_object(me, "Ч������("+(i+300)+")���������ڹ�("+i/2+")��\n");
		}
		else if( wizardp(me) ) tell_object(me, "Ч�����ظ�ʹ�ã���Ч����\n");
	}

	return 1;
}

void remove_effect(object me, int count)
{
	if( !me ) return;

	if( !me->is_ghost() && count-- > 0 ) {
		call_out("remove_effect", 10, me, count);
		return;
	}

	if( me->query_temp("music_force") > 0 )
		me->add_temp("apply/force", -me->query_temp("music_force") );

	if( me->query_temp("music_parry") > 0 )
		me->add_temp("apply/parry", -me->query_temp("music_parry") );

	if( me->query_temp("music_dodge") > 0 )
		me->add_temp("apply/dodge", -me->query_temp("music_dodge") );

	if( me->query_temp("music_damage") > 0 )
		me->add_temp("apply/damage", -me->query_temp("music_damage") );

	if( me->query_temp("music_armor") > 0 )
		me->add_temp("apply/armor", -me->query_temp("music_armor") );

	if( me->query_temp("music_attack") > 0 )
		me->add_temp("apply/attack", -me->query_temp("music_attack") );

	if( me->query_temp("music_strength") > 0 )
		me->add_temp("apply/strength", -me->query_temp("music_strength") );

	if( me->query_temp("music_dexerity") > 0 )
		me->add_temp("apply/dexerity", -me->query_temp("music_dexerity") );

	if( me->query_temp("music_intelligence") > 0 )
		me->add_temp("apply/intelligence", -me->query_temp("music_intelligence") );

	if( me->query_temp("music_constitution") > 0 )
		me->add_temp("apply/constitution", -me->query_temp("music_constitution") );

	me->delete_temp("music_force");
	me->delete_temp("music_parry");
	me->delete_temp("music_dodge");
	me->delete_temp("music_damage");
	me->delete_temp("music_armor");
	me->delete_temp("music_attack");
	me->delete_temp("music_strength");
	me->delete_temp("music_dexerity");
	me->delete_temp("music_intelligence");
	me->delete_temp("music_constitution");

	if( wizardp(me) ) tell_object(me, "��ϵͳ������Ч��������\n");

	return;
}
