// ���쾢����Ծ��yinyun-ziqi/lifesave.c
// Write by Cht 1999.9.2
// Modify by snowman@SJ 20/01/2000
// exp ֻ�ָ�һ�롣

#include <ansi.h>
inherit F_SAVE;

string exert_name(){ return HIG"���쾢����Ծ��"NOR; }

int exert(object me,object corp)
{
	object obj, where;
	int i;
//	string *No_Save_Id;

	where = environment(me);

	if ( !present(corp,where) )
		return notify_fail("ָ���ʽ��yun lifesave corpse\n");

	if( !corp )
		return notify_fail("ָ���ʽ��yun lifesave corpse\n");

	if ( corp==me )
		return notify_fail("�����ڻ����ܾ��Լ���\n");

	if ( userp(corp) )
		return notify_fail("�㿴��������ǻ��ˣ�����\n");

	if ( !corp->is_corpse() )
		return notify_fail("�ǲ���ʬ��Ү��������ë������\n");

	if (corp->query("no_head"))
		return notify_fail("ͷ�Ѿ������ˣ����˰ɡ�\n");

	if ((string)corp->query("name") == "���õ���ʬ" || (string)corp->query("name") == "���õ�Ůʬ")
		return notify_fail("�����ˣ���ʹ��������ͷ�ɡ�\n");

	if( userp(me) && ((string)me->query_skill_mapped("force") != "yinyun-ziqi"))
		return notify_fail("����ڹ����ԡ�\n");

	if ( !userp(me))
		return notify_fail("");

	if((int)me->query_skill("yinyun-ziqi", 1) < 350 )
		return notify_fail("��ġ������������𲻹����������á����쾢����Ծ�ϡ����ˡ�\n");

	if((int)me->query_skill("taoism", 1) < 180 )
		return notify_fail("��ԡ���ѧ�ķ���������������á����쾢����Ծ�ϡ����ˡ�\n");

	if((int)me->query_skill("medicine", 1) < 120 )
		return notify_fail("�㻹�ö�ѧ���ľҩ��\n");

	if( (int)me->query("max_neili", 1) < 3000 )
		return notify_fail("���������Ϊ̫�������������á����쾢����Ծ�ϡ����ˡ�\n");

	if( me->query("family/family_name") != "�䵱��")
		return notify_fail("�󵨣���͵ѧ�䵱������ȥ���ɡ�����\n");

	if( !corp->query("victim_user"))
		return notify_fail(corp->name()+"�ɲ������ʬ��Ŷ��\n");

	if ( corp->query("group_war"))
		return notify_fail(corp->name()+"���ڰ���ս���������ģ��㲻�����á����쾢����Ծ�ϡ����ˡ�\n");

	if ( !objectp( obj = find_player(corp->query("victim_id")) ))
		return notify_fail(corp->query("victim_name")+"�Ļ��ǲ�����Ϸ�\n");

	if (!interactive(obj))
		return notify_fail("����û�����ߡ�\n");

	if (!obj->is_ghost())
		return notify_fail(obj->name() + "�Ѿ�������ˣ�������ȡ�\n");

	if( me->query_temp("lifesaved"))
		return notify_fail("��һ�������٣��㱾�������Ѿ��ȹ����ˡ�\n");

	i = me->query("lifesave_times");
	if ( me->query("combat_exp", 1)/ 500000 <= i)
		return notify_fail("�ϴξ��ˣ������Ĺ��࣬���ڵ��������������á����쾢����Ծ�ϡ����ˡ�\n");

/*
	if( file_size("/log/skills/no_lifesave") > 0 ){
		No_Save_Id = explode(read_file("/log/skills/no_lifesave"), "\n");
		if( sizeof(No_Save_Id) > 0 && member_array(getuid(obj), No_Save_Id) != -1 )
			return notify_fail("����Ϊ�䵱��У���Ҫ����ʦ�ţ���\n");
	}
*/
	me->add_busy(5);

	message_vision(HIY"ֻ��$N˫��ʳָ��Ĵָ���ã��ɡ�"HIW"���쾢"NOR""HIY"���ƣ���ʳָָ�����$n�������ִ��ġ���Ծ�ϡ���\n"
			"�����ڹ���΢΢�ڶ����⡰"NOR""HIW"���쾢����Ծ��"NOR""HIY"��ʹ�������������¶���֮��Ҳ�ܻ���Ƭ�̡�����\n"NOR, me, corp);

	call_out("do_save",3,me,corp,obj);
	return 1;
}

void do_save(object me,object corp,object obj)
{
	mapping learned;
	int j,yyzq_drop,yyzq_lvl;

	if (!me || !corp || !obj) return;
	if (!present(corp, environment(me))) return;
	if (!interactive(obj)) return;
	if (!obj->is_ghost()) return;

   j = random(20);
	yyzq_lvl = me->query_skill("yinyun-ziqi",1);
   yyzq_drop = random(yyzq_lvl); //��ǰ��yyzq_lvl*yyzq_lvl 
	learned = me->query_learned();

	tell_object(obj, HIY "\nһ��������������㣬ʹ���㼸��������ȥ��\n\n" NOR);

	message_vision(HIC"\n��һ�ᣬ$N��ͷ��ð�������飬$nҲ�ƺ�����һ�¡���\n\n"NOR,me,corp);

	me->add("max_neili",-j );
	learned["yinyun-ziqi"] -= yyzq_drop;
	me->add("shen", yyzq_drop / 10);

	if( learned["yinyun-ziqi"] < 0) {
//           me->set_skill("yinyun-ziqi",yyzq_lvl-1);
           learned["yinyun-ziqi"] = 0;
	}

	obj->add("lifesaved", 1);

   if( me->query("neili") < 2000 || random(me->query_skill("taoism", 1)) < 40){
		me->set("neili", 0);
		tell_object(me, HIR"��Ȼ���㷢���Լ��Ѿ��������Ĵ������޷���֧���ˣ�\n"NOR);
		log_file("skills/lifesave",sprintf("%-18s û�оȻ�(1)%s�������� %d �����������\n",
			me->name(1)+"("+me->query("id")+")", obj->name(1)+"("+obj->query("id")+")", j), me);
		me->unconcious();
		return;
	}

	me->add("neili",-2000);
	if( !interactive(me) 
	|| query_ip_number(me) == query_ip_number(obj)
	|| me->query("last_lifesave") == obj->query("id")
	|| obj->query("lifesaved") % 2 == 0 ){
		tell_object(me, HIR"ͻȻ��ȫ��һ��һ����ʧȥ��"+obj->name()+"�Ļ��ǣ�\n"NOR);
		me->unconcious();
		me->delete("last_lifesave");
		tell_object(obj, HIR"����������������Խ��Խʢ��ͻȻƾ�մ���һ������޺ȣ������˲������뿪�˵أ���\n"NOR);
		log_file("skills/lifesave",sprintf("%-18s û�оȻ�(2)%s�������� %d �����������\n",
			me->name(1)+"("+me->query("id")+")", obj->name(1)+"("+obj->query("id")+")", j), me);
		obj->unconcious();
		return;
	}

	tell_room(environment(obj), HIY + obj->name(1)+"����һ�����������ʧ�ˣ�\n"NOR, obj);
	message_vision("һ�ƻ��ǹ鵽ʬ���ϣ�$n��Ȼ�λ����Ƶ�վ������\n\n", me, corp);
	destruct(corp);
	obj->move(environment(me));
	"/cmds/wiz/recover"->do_recover(obj, 1);
	obj->unconcious();
	obj->set("last_death", "����"+me->query("name")+"("+me->query("id")+")�Ȼ�");

	tell_object(me, "��˴ξ��˹��ķ���"+CHINESE_D->chinese_number(j)+"����������������������½���"+CHINESE_D->chinese_number(yyzq_drop)+"�㡣\n");
	me->set("last_lifesave", obj->query("id"));
	me->set_temp("lifesaved", 1);
	me->add("lifesave_times", 1);
	if ( me->query("lifesave_exp"))
		me->delete("lifesave_exp");
	log_file("skills/lifesave",sprintf("%-18s �Ȼ� %s���ķ��� %d �����������\n",
		me->name(1)+"("+me->query("id")+")",obj->name(1)+"("+obj->query("id")+")", j), me);
}

int remove()
{
	save();
	return 1;
}

string query_save_file()
{
	return "/log/mine_rank";
}

int help(object me)
{
	write(WHT"\n�����������쾢����Ծ�ϡ���"NOR"\n");
	write(@HELP
	�䵱һ�ɣ��ó��������ˣ��������¶����ˣ��ú��쾢����Ծ�ϵĹ���δ
	�ز��ɻ��꣬�˷�������Ծ����ߴ�����Ԫ������������������Ϣ��

	Ҫ��	�������ȼ� 350 ���ϣ�
		��ѧ�ķ��ȼ� 180 ���ϣ�
		��������ȼ� 120 ���ϣ�
		������� 3000 ���ϡ�

HELP
        );
        return 1;
}
