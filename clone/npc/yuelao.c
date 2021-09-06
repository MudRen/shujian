// yuelao.c ��������
// Update by Lklv for ������飬������������Ҫ 2002.5.23

// 90�첻���ߣ�����ȱϯ���
// Modified By Rascal Ciwei@SJ
#define LIHUN_TIME 90

inherit NPC;
#include <mudlib.h>

int do_register();
int do_zuomei(string);
int do_divorce(string);

void create()
{
	set_name("��������", ({ "yuexia laoren", "yuelao", "laoren" }));
	set("long",
		"�����Ǵ�˵��ר�����ϵ�����Ե�����������ˡ�\n"
		"��������⣬��ü�԰ף��������Ѳ�֪�ж������ˡ�\n"
		"���������Ƕ�����һ���飬�������һ����������������������Щʲô��\n");
	set("gender", "����");
	set("age", 3000);
	set("attitude", "friendly");
	set("str", 500);
	set("int", 500);
	set("con", 300);
	set("per", 325);
	set("no_quest", 1);

	set("max_qi", 10000);
	set("max_jing", 10000);
	set("combat_exp", 20000000);

	set_skill("force", 500);
	set_skill("dodge", 800);
	set_skill("unarmed", 500);
	set_skill("parry", 800);
	set_skill("literate", 900);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	add_action("do_register", "register");
	add_action("do_register", "jiehun");
	add_action("do_divorce", "divorce");
	add_action("do_divorce", "lihun");
	add_action("do_zuomei", "zuomei");
}

int do_register()
{
	object me, who, meiren;
	int wiz;
	me = this_player();

	message_vision("$N���������$n��ǰһվ��\n", me, this_object());
	if (!me->query_temp("marry")) {
		command("? "+ me->query("id"));
		command("say �ף�������Ե����û���������ѽ ... ...");
		command("say ���������Ȼ�ȥ�����Ҹ����ҵ�������Ե�����ɡ�");
		return 1;
	}
	if (me->query("gender")=="Ů��") {
		command("pat "+ me->query("id"));
		command("say �ţ������δ�����ǰ����");
		return 1;
	}
	if (!objectp(who=present(me->query_temp("marry"),environment(me)))) {
		command("? "+ me->query("id"));
		command("say �ţ������Ե�����ˣ�����Ϊʲô���δ����ûһ������");
		command("say ������δ���޵����������Ҳ���Ϊ������ɵǼ�������");
		return 1;
	}
	if (who->query_temp("marry")!=me) {
		command("? "+ me->query("id"));
		command("say �����������δ����Ϊ���ִ�Ӧ��������ˣ�����");
		command("say �����뿪ʲô��Ц�������������������");
		return 1;
	}
	wiz = wizardp(me)||wizardp(who);
	if (!wiz && !who->query_temp("meiren")) {
		command("pat "+ me->query("id"));
		command("say ����Ե��׻�˵�ĺá���ĸ֮����ý��֮�ԡ�������̶���޸�ĸ����Ҳ���ˡ�");
		command("say ������ý��֮�ԣ���Ҳ̫�����ˡ�");
		command("say ����ȥ�Ҹ�ý�����ɣ������ڴ���֤���Ҳ���Ϊ�������顣");
		return 1;
	}
        if (!wiz && !objectp(meiren=present(who->query_temp("meiren"),environment(me)))) {
        	command("pat " + me->query("id"));
                command("say �ţ�����˶�������ˣ�������ý�������Ķ�ȥ����");
                command("say ���ý���ҵ���������Ҳ���Ϊ������ɵǼ�������");
                return 1;
        }
        
        if(wiz && sizeof(filter_array(all_inventory(environment(me)) - ({ me,who }), (: interactive :))) ){
		tell_object(who,"�����ȵȵȰ� ������ղ�����\n");
		tell_object(me,"�����ȵȵȰ� ������ղ�����\n");
		return 1;
	}
	
	command("say �����������ü��ˣ�һ���뱸�������Ϊ���ǵǼǣ�");
	message_vision("�������˵�ͷ����Ե�����˷���д��Щʲô��\n", me);
	command("say ��ϲ����ϲ��");
	if(wiz) command("say ��ף��λ��ͷ���ϣ��������ӡ�");
        else {
		command("chat ����������������");
		command("chat "+me->name()+"��"+who->name()+"��"+meiren->name()+"��ý������ϲ����Ե����λ����������֤��");
		command("chat ��ף��λ��ͷ���ϣ��������ӡ�");
	}
	
	who->delete_temp("marry");
	who->delete_temp("meiren");
	who->set("marry/id",me->query("id"));
	who->set("marry/name",me->query("name"));
	me->delete_temp("marry");
	me->set("marry/id",who->query("id"));
	me->set("marry/name",who->query("name"));
	me->set_temp("marrying",1);
	me->set_temp("bride", who->query("id"));
	who->set_temp("groom", me->query("id"));
	new("/clone/misc/marry-token")->move(me);
	new("/clone/misc/marry-token")->move(who);
	me->save();
	who->save();
	message_vision("$N��$n�����˶������\n", me, who);
	return 1;
}

int do_zuomei(string arg)
{
	object me, who;
	me = this_player();

	if (me->query("age") < 18) {
		write("�㻹С��û���ʸ���ý��\n");
		return 1;
	}
	if (!arg || !objectp(who=present(arg,environment(me)))) {
		write("��Ҫ��˭��ý��\n");
                return 1;
	}
	if (me==who || me==who->query_temp("marry")) {
		write("�Լ����Լ���ý����̫�ðɣ�\n");
		return 1;
	}
	if (who->query("gender")!="Ů��") {
		write("�ţ���ý��ΪŮ����ý��\n");
		return 1;
	}
	if (!who->query_temp("marry")) {
		write("�ţ�����û�����鰡����Ϲ��ʲô�壿����\n");
		return 1;
	}
	if (who->query_temp("meiren")) {
		write("�Ѿ�����Ϊ����ý�ˡ�\n");
		return 1;
	}
	message_vision("$N���Ц�ݣ�����������һ��ȭ�������Ǹ������ӣ�\n", me);
	command("say "+RANK_D->query_respect(me)+"Ը���"+who->name(1)+"��ý��");
	command("say ����ǳ���֮�������°����ü��ˣ�����ͼ�������");
	who->set_temp("meiren", me);
	return 1;
}

int do_divorce(string arg)
{
	object me, who;
	string tmp, tmp2, site_name, darling;
	int lapse, i;
	int last_on;
	int wiz = 0;

	seteuid(ROOT_UID);

	me = this_player();
	site_name = INTERMUD_MUD_NAME;
	me->query("gender")=="����"?darling = "����":darling = "�ɷ�";
	
	if (!me->query("marry")) {
		command("say �����û����飡");
		return 1;
	}
	if(!arg) arg=me->query("marry/id");//�����Լ����������ѵ�����������鰡
	if (!arg) {
		command("say ������˭��飿\n");
		return 1;
	}
	if (me->query("marry/id") != arg) {
		command("? "+ me->query("id"));
		command("say ���˸������������ż��");
		return 1;
	}
	wiz = wiz_level(me)||wiz_level(arg);
// Modified by mxzhao 2004/02/18
		{
			mixed ret = dbquery("select U_Site from Users "
				"where U_Username="+save_variable(arg));

			if (sizeof(ret) == 1)
			{
				tmp = ret[0][0];
			}
			else
			{
				tmp = "�Ѿ���ɱ";
			}
		}

/*
	{
		mixed mysql = db_connect("localhost", "mud", "root"), rows, res = ({ "�Ѿ���ɱ" });

		if (intp(mysql)) {
			rows = db_exec(mysql, "select U_Site from " + INTERMUD_MUD_NAME + "_Users where U_Username="+save_variable(arg));
			if (rows==1)
				res = db_fetch(mysql, 1);
			db_close(mysql);
		}
		tmp = res[0];
	}

// End

	if (tmp == "�Ѿ���ɱ") {
		command("sigh ");
		command("say ���"+darling+"�Ѿ���ɱ�ˣ�������ɡ�");
		return 1;
	}
	
	if ( tmp != site_name){
		command("shake");
		command("say ���"+darling+"�������վ�㣬��ȥ����վ�������������ɡ�");
		return 1;
	}
*/	
	if (!who=find_player(arg)) {
		
		who = new(LOADUSER_OB, arg);
		if (!who->restore()) {
			destruct(who);
			command("poor");
			command("say ��"+darling+"�����������⣬֪ͨ��ʦ�ɡ�");
			return 1;
		}

		last_on = who->query("check_point");
		destruct(who);
		
		lapse = time() - last_on;
		tmp2 = CHINESE_D->chinese_time(lapse);

		// 90�첻�������!
		i = 60*60*24*LIHUN_TIME;
		
		// ������Ϣ
		if (wizardp(me)){
			write("��ż��������վ��"+tmp+"\n");
			write("�ϴ�����"+last_on+"\n");
			write("����ʱ���"+lapse+"\n");
			write("����ʱ�䣺"+tmp2+"\n");
			write(i+"����ʱ��"+CHINESE_D->chinese_time(i)+"\n");
			write("��ǰվ�� = "+site_name+"\n");
		}
		
		if ( lapse < i ) {
			command("pat "+ me->query("id"));
			command("say �Բ�����"+darling+"���ڲ������ϣ����ܰ����������");
			return 1;
		}
		if (!me->query_temp("divorcing")) {
			command("ah "+ me->query("id"));
			command("say �����㵱��������"+darling+"���������ǣ�������������һ�Ρ�");
			me->set_temp("divorcing",1);
			return 1;
		}
		command("shrug "+ me->query("id"));
		command("say ���"+darling+"������ʮ��û�������ˣ����԰����������");

		// �鷳��!
		// ����������С�ӵ����״̬��restore ����Ȼ����save ��ȥ ����ôд��
		// ���鷳����ôд������
		who = new(LOADUSER_OB, arg);
		who->restore();
		darling = who->query("name");
		who->delete("marry");
		who->add("divorce", 1);
		who->set_temp("db_quit", 1);
//		who->save();
		destruct(who);
		if(!wiz) command("chat ��Ϊ"+darling+"�Ѿ�������ʮ��û�������ˣ�"+me->query("name")+"�����������������״̬��");
	} else {
		command("say �� ... ...");
		who->delete("marry");
		who->add("divorce", 1);
		tell_object(who, me->name(1)+"�������㣬��֪�Ǹ�˭˽��ȥ�ˡ�\n");
		if(!wiz) command("chat �ӽ�����"+me->name(1)+"��"+who->name(1)+"�Ͳ����Ƿ����ˡ�");
		if (present("yu pei", who)) present("yu pei", who)->lost(who);
		if (present("xiang nang", who)) present("xiang nang", who)->lost(who);
	}
	me->delete_temp("divorcing");
	me->delete("marry");
	me->add("divorce", 1);
	if(!wiz) command("chat ��һ׮ʧ�ܵĻ������� ... ... ");
	if (present("yu pei", me)) present("yu pei", me)->lost(me);
	if (present("xiang nang", me)) present("xiang nang", me)->lost(me);
	return 1;
}
