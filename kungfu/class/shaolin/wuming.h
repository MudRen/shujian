// wuming.h

int ask_fofa()
{
	object me=this_player();

	if(!me->query("guilty")){
		command("buddhi wuming");
		return 1;
	}
	if(me->query_skill("buddhism",1) < 200) {
		command("say ��ʦ����Ϊ���㣬�������޷��㲦���㡣");
		return 1;
	}
	if( me->query("family/master_name") != "������ɮ")
		return 0;
	if( me->query("shen") < 0) {
		command("say ����ȼ�թС�ˣ������ܴ���𷨣�\n");
		return 1;
	}
	command("buddhi");
	message_vision(HIW"������ɮ����������ļ��𣬼����ģ�����ʶ��ʶ�����ģ����ķǷ������ġ���\n"NOR, me);
	message_vision("$N��˼���ã��������档\n", me );
	me->add_busy(5);
	me->delete("guilty");
	return 1;
}

int ask_reset_skill()
{
	object me = this_player();

	if ( me->query("family/family_name") != "������") return 0;
	if ( me->query("family/master_name") != "������ɮ"){
		command("say ��Ĺ���������������ȥ����һ��ɡ�");
		return 1;
	}
	if (me->query("passdu") && me->query_skill("riyue-bian", 1) > 200) {
		command("nod");
		command("say �һ�����ȥ��������˵��������쿪ʼ��ȥ��������ϰȼľ�����ɡ�");
		message_vision(HIR"$N��Ϊǿ�з�����ԭ����ϰ�������񹦣����ڻ�������������˴�롣\n"NOR, me);
		me->delete_skill("riyue-bian");
		me->set("max_neili", me->query("max_neili")/2);
		me->delete("passdu");
		me->set("pass_xin", 1);
		me->set("no_recover", 1);
		return 1;
	}
	if (me->query("pass_xin") && me->query_skill("ranmu-daofa", 1) > 200) {
		command("nod");
		command("say �һ�����ȥ��������˵��������쿪ʼ�͸�������ѧϰ���±޷��ɡ�");
		me->delete_skill("ranmu-daofa");
		message_vision(HIR"$N��Ϊǿ�з�����ԭ����ϰ�������񹦣����ڻ�������������˴�롣\n"NOR, me);
		me->set("max_neili", me->query("max_neili")/2);
		me->delete("pass_xin");
		me->set("no_recover", 1);
		me->set("passdu", 1);
		return 1;
	}
	command("buddhi");
	command("say ��ԭ�����似��δ�����죬��ô��̰�������似�أ�");
	return 0;
}

string ask_wtc()
{
	int i;
	object me = this_player();

	if ( me->query("family/master_name") != "������ɮ")
		return "�㲻���ҵĵ��ӣ�������������ȥ�����ɡ�";

	if ( me->query("sl_wtc"))
		return "�㲻���Ѿ�ѧ�����־���Τ������ô��";

	if ( me->query("max_neili") < 6000){
		i = 6000 - me->query("max_neili");
		return "Τ���ƹ������ͣ������������"+CHINESE_D->chinese_number(i) +"�����������";
	}
	if ( me->query_skill("buddhism", 1) < 200)
		return "Τ���ƹ������ͣ���ķ���Ϊ��������";

	if ( !me->query("passdu") && !me->query("pass_xin"))
		return "��û��������ȼľ���������±޷������ֱ����似����";

	if ( me->query_temp("sangong"))
		return "����ɢ���Ļ����Ұ��㻤�����Ͳ���Ҫ�����ˡ�";

	if ( me->query("passdu"))
		me->set_temp("sangong", "passdu");

	if ( me->query("pass_xin"))
		me->set_temp("sangong", "pass_xin");

	command("buddhi");
	command("say ����������ϰ���־���Τ���ƣ�����ɢȥԭ���������书����������");
	command("pat "+ me->query("id"));
	return "��������Ļ�������������ɢ��(sangong)�����İ��㻤���ɡ�";
}

string ask_sangong()
{
	object me = this_player();

	if ( me->query_temp("sangong"))
		return "����ɢ���Ļ����Ұ��㻤�����Ͳ���Ҫ�����ˡ�";

	if ( me->query("family/master_name") != "������ɮ")
		return "�㲻���ҵĵ��ӣ��γ����ʣ�";

	if ( me->query("sl_wtc"))
		return "���Ѿ�ѧ�����־���Τ�����ˣ���ɢ���к����档";

	if ( me->query_skill("buddhism", 1) < 200)
		return "��ķ���Ϊ�����������ɢ����";

	command("buddhi "+me->query("id"));
	return "ɢ����ѧϰΤ���Ƶ�Ψһ;������Ҫ�о�Τ�����";
}