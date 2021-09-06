// change_name.h  for change name npc ps: zhaochengzhi.c
// Lklv change to thisfile for zhao

// Modified by mxzhao 2004/02/18
// Modified by lInuX 2004/04/01
#include <database.h>

void init()
{
	add_action("change_name", "zhuce");
}

private int change_name(string arg)
{
	string new_name, name, f_mname, f_class;
	int i, f_gen;
	object me = this_player();

	if (!me->query_temp("name_modify_paid") && !wizardp(me)) {
		command("say ��͢���Ĺ涨��ƽ�񲻵�����������գ����������ǲ��ǣ�");
		return 1;
	}

	if ( !arg ) {
		command("say �㵽��Ҫ��ʲô���ְ���");
		return 1;
	}

	name = me->query("name");
	new_name = arg;
	f_gen = me->query("family/generation");
	f_class = me->query("class");
	f_mname = me->query("family/master_name");

	switch(me->query("family/family_name")){
		case "�һ���":
			if (f_gen == 2) {
				if (strlen(arg) != 6 || arg[4..5] != "��")
					return notify_fail("������ֱ����������֣������Է��β��\n");
			}
			break;
		case "������":
		case "������":
		case "������":
			if (f_class == "bonze" || f_class == "huanxi") {	// ������һ����Ǯȥ�� huanxi �Ļ���
				if (strlen(arg) != 4)
					return notify_fail("������ֱ����������֡�\n");
				switch (f_gen) {
					case 40:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 39:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 38:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 37:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 36:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 35:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 14:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 13:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 5:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 4:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					case 3:
						if (arg[0..1] == "��")
							break;
						return notify_fail("���ֲ��ԣ�������\n");
					default:
						if (name[0..1] != arg[0..1])
							return notify_fail("��ķ��ű����������֣����ҵ�һ���ֲ��ܱ䡣\n");
				}
				if (f_class == "huanxi")
					me->set("class", "bonze");
			} else if (f_mname == "������")
				if (strlen(arg) > 6 || arg[0..1] != "��")
					return notify_fail("����������������������֣����ҵ�һ���ֱ���Ϊ�Ρ�\n");
			break;
		case "������":
			if (f_gen == 2) {
				if (strlen(arg) != 6 || arg[4..5] != "��")
					return notify_fail("������ֱ����������֣��������ӽ�β��\n");
			}
			break;
		case "����Ľ��":
			if (f_gen == 2) {
				if (strlen(arg) < 6 || arg[0..3] != "Ľ��")
					return notify_fail("������ֱ������������֣�������Ľ�ݿ�ͷ��\n");
			}
	}

	i = strlen(new_name);

	if (i < 4 || i > 8 || i%2) {
		command("say ��"+new_name+"����");
		command("say ����������ֱ����� 2 �� 4 �������ֲ��С�");
		return 1;
	}

	while(i--)
		if( i%2==0 && !is_chinese(new_name[i..<1]) ) {
			command("say ����á����ġ�ȡ���֣������ҿɲ���ʶ�����֡�");
			return 1;
		}

	if (!wiz_level(me->query("id"))
	&& (!"/adm/daemons/named"->valid_name(new_name) ) ){
		command("say ���������ֻ���������˵����ţ���������ġ�");
		return 1;
	}
/*
// Modified by mxzhao 2004/02/18
	{
		mixed ret = dbquery("select U_Name from Users where U_Name='"+new_name+"'");
		if (!ret)
		{
			return notify_fail("��ʱ�����޸�������\n");
		}

		if (sizeof(ret) > 0)
		{
			return notify_fail("�Ѿ����������ʹ�������������\n");
		}

		if (!dbquery("update Users set "
			"U_Name='"+new_name+"' "
			"where U_Username='"+me->query("id")+"' limit 1"))
		{
			return notify_fail("���ݿ����ʧ�ܡ�\n");
		}
		if (!BBS_D->add_Bbs_Up_Map(WEB_DB_NAME, "UPDATE members SET cname = 
		'"+new_name+"' WHERE username = '"+
		me->query("id")+"@"+lower_case(INTERMUD_MUD_NAME)+"' limit 1"))
		{
			return notify_fail("WEB���ݿ����ʧ�ܡ�\n");
		}
	}
	
	{
		mixed mysql = db_connect("localhost","mud","root");

		if (!intp(mysql))
			return notify_fail("��ʱ�����޸�������\n");
		if (db_exec(mysql, "select U_Name from " + INTERMUD_MUD_NAME + "_Users where U_Name='"+new_name+"'")) {
			db_close(mysql);
			return notify_fail("�Ѿ����������ʹ�������������\n");
		}
		db_exec(mysql, "update " + INTERMUD_MUD_NAME + "_Users set "
			"U_Name='"+new_name+"' "
			"where U_Username='"+me->query("id")+"' limit 1"
		);
		db_close(mysql);
	}
*/
// End

	me->set("name", new_name);
	me->add("name_modify", 1);
	command("chat �ӽ��Ժ�"+name+"("+getuid(me)+") ������Ϊ��" + new_name + "��");
	log_file("name_modify",
		sprintf("%-18s �� %d �θ���Ϊ��%s\n",
			name+"("+getuid(me)+")", me->query("name_modify"), new_name
		), me
	);
	me->delete_temp("name_modify_paid");
	start_busy(2);
	if (new_name == name)
		command("say ���������Ǯ���ҿ������ţ����˸�һģһ�������֡�");
	command("say ��Ļ��������Ѿ�������ϣ���������ˡ�");
	return 1;
}

string ask_me()
{
	object me = this_player();
	string mname = (string)me->query("name");

	if(me->query_temp("name_modify_paid")){
		command("nod");
		return "�ðɣ���ֻҪע��( zhuce <����> )��������־����ˡ�\n";
	}

	if(mname == "���ִ���"){
		me->set_temp("name_modify_paid", 1);
		return "�����������գ�����ͬ���������Ҫע��( zhuce <����> )ʲô���֣�";
	}

	if( this_object()->is_busy())
		return "����æ�Ÿ�д�����أ���ȵȡ�";

	if(me->query_temp("name_wait_modify")){
	       command("hmm");
	       return "���Ǹ������㣬���²���ô�ð���\n";
	}

	if (!wiz_level(me->query("id"))
	&& (!"/adm/daemons/named"->valid_name(mname) )) {
		command("pat");
		me->set_temp("name_modify_paid", 1);
		return "���Ѿ��õ�֪ͨ��������ĸ������ã���Ҫ����( zhuce <����> )ʲô���֣�";
	}
	command("consider");
	command("say "+me->query("name", 1)+"���������ն�Ҫ�޸Ļ��������������پ������º��Ѱ�......\n");
	me->set_temp("name_wait_modify", 1);
	if(me->query("class") == "bonze")
		command("say ���ˣ����У���ÿɸĲ��˱��ֳƺš�\n\t������� ��һ���ͱ��� zhuce �Ա��ֿ�ͷ�����֡�");
	if( me->query("registered") == 3 )
		return "�������Ҫ�ģ��������ǹ����ң��ϱ�����������"+chinese_number(100*(me->query("name_modify")+1))+"���ƽ𣬽������ʷ����\n";
	else
		return "�������Ҫ�ģ��ϱ�����������"+chinese_number(200*(me->query("name_modify")+1))+"���ƽ𣬽������ʷ����\n";

}	
