// bags_up.h ؤ������ system
// Newcode by looklove 2000/8/25
// change gb_up.c to gabs_up.h at 2001.9.28 and recode

int promotion_checking(object who, object ob);

mixed names = ({
({"���¾�", "ɳ��", HIM"�ۺ����"NOR,"ţƤ�ƴ�","����","ָ��","��","����",
"��վ�","����ȭ��","̫��ʮ����","��Ƥ","���ᱸ����","����Ƥ","���"}),
({"�鲼��","������","Χ��","����Ƥ",HIW"��Կ��"NOR,"��¨","�廨��",
"���޺�","������Ҫ","ͼ��","����ɢ","����������","Ԣ���"}),
({"�ڹ��ķ�","ϴ�辭",YEL"ǧ������"NOR,"����","���޶���","Ħڭɮڮ��"}),
});

void dest(object ob)
{
    	if (ob) destruct(ob);
}

int get_object(object ob)
{
        if(userp(ob)) return 1;
        return 0;
}

int accept_object(object who, object ob)
{
    	if (promotion_checking(who, ob)) {
        	call_out("dest", 1, ob);
        	return 1;
    	}
    	return 0;
}

string ask_me()
{
        object ob, me;
        int bg_lvl, bags, exp, htlvl;
        string target;

        me = this_player();
        ob = this_object();
	bags = (int)me->query("gb/bags");  		// Ŀǰ����
	bg_lvl = (int)me->query_skill("begging",1); 	//�л������
	exp = (int)me->query("combat_exp",1); 		// ��ǰexp
	htlvl = (int)me->query_skill("huntian-qigong",1); //������������

	if ( me->query("family/family_name") != "ؤ��" )
		return RANK_D->query_respect(me)+"���Ǳ�����ӣ����д��ʣ� ";

	if ( me->query_temp("sd_target"))
		return RANK_D->query_respect(me)+"�Ҳ�������ȥ��"+me->query_temp("sd_target")+"���𣿿�ȥ�ɡ�";

	if ( bags >= 3 )
		return RANK_D->query_respect(me)+"�Ѿ���ѹȺ���ˣ���֪���Ͷ��١�";

	if ( bg_lvl < 60 && bags >= 2 )
		return RANK_D->query_respect(me)+"�Ľл�����ȼ���������Ҫ�����ͣ�";

	if ( bg_lvl < 30 || bags < 1)
		return RANK_D->query_respect(me)+"�ڰ���������ǳ���л�����ȼ�������������������";

	if ( me->set_temp("sd_target"))
		return "������ȥ��";

        target = names[bags-1][random(sizeof(names[bags-1]))];
        me->set_temp("sd_target", target);
        return "�ðɣ�����Ҫ�����������Ū��ɼ���������ȥ��" + target +CYN"����������";
}

int promotion_checking(object who, object ob)
{
	int bag,exp;
	if ( who->query("family/family_name") != "ؤ��" )
		return 0;
	if ( ob->query("name") != (string)who->query_temp("sd_target")) {
		command("say �ⶫ����Ҫ��û�á�");
		return 0;
	}
	if (userp(ob)) {
		command("say " + RANK_D->query_rude(who) +"����Ȼ����ƭ���������������ѣ�");
		return 0;
	}

	bag=(int)who->query("gb/bags",1);
	exp=(bag*500);
	who->add("gb/bags",1);
	who->add("max_neili",10);
	who->add("combat_exp",exp);

	command("nod " + who->query("id"));
	command("say �ɵúã��ӽ��쿪ʼ�������Ϊ"+chinese_number(who->query("gb/bags")) + "�����ӣ��úøɣ�\n");
	who->set("title",sprintf("ؤ��%s%s������", who->query("gb/fenduo"),chinese_number(who->query("gb/bags"))));
	who->delete_temp("sd_target");
	return 1;
}

int ask_bag()
{
    	object me = this_player();
    	int i, bag ,lvl;
    	mapping skl;
    	string *sname, fenduo;

	bag = me->query("gb/bags");
	lvl = bag - 2 ;
	fenduo = me->query("gb/fenduo");

	if (me->query("family/family_name")!="ؤ��" ) {
		command("say " + RANK_D->query_respect(me) + "����ؤ�������������˻���֪�Ӻ�˵��\n");
		return 1;
	}
	if ( bag < 3 ){
		command("say " + RANK_D->query_respect(me) + "�ڰ���ְλ̫�ͣ��ȼ��������ɡ�\n");
		return 1;
	}
	if (bag == 9 ){
        	command("say " + RANK_D->query_respect(me) + "�ڰ������ǾŴ����ϣ�������������ȥ��\n");
		command("sneer "+me->query("id"));
		if (!me->query("title"))
			me->set("title",HIW"ؤ��Ŵ�����"NOR);
		return 1;
	}

	if (me->query("relife/relifed")) {
        	command("say " + RANK_D->query_respect(me) + "�����Ұ��п��䳤�ϣ�����С����Ͳ������ˡ�\n");
		command("praise "+me->query("id"));
		if (!me->query("title"))
			me->set("title",HIM"ؤ����䳤��"NOR);
                        me->set("gb/bags",9);

		return 1;
	}

	if ((int)me->query("shen") < 100000 * lvl ){
		command("say ��ؤ���������������ɣ�"+RANK_D->query_respect(me) +"�Ƿ�Ӧ�ö���������֮�¡�");
		return 1;
	}
	if ((me->query_skill("huntian-qigong",1)) < (bag+1) * 25 ){
		command("say ���������������书�ĸ�����"+RANK_D->query_respect(me) +"�����Ϊ"+chinese_number(bag+1)+"�����ӣ�����Ҫ�ﵽ "+chinese_number((bag+1)*25)+" ���ſ��ԡ�");
		return 1;
	}
	if ((me->query("job_time/ؤ��") + me->query("job_time/��Ч����") + me->query("job_time/ץ��")) <  200 * bag ) {
		command("say ��ؤ���������������ɣ�"+RANK_D->query_respect(me)	+"Ӧ��Ϊ��Ϊ������㹱�ײźá�");
		command("say û�µ�ʱ���ȥ���¡�³������λ���ϰɡ�");
		return 1;
	}

	skl = me->query_skills();
	if (mapp(skl)) sname = keys(skl);

	for(i=0; i<sizeof(skl); i++){
		if (SKILL_D(sname[i])->type2() == "worker") continue;
		if ( me->query_temp("user_type") =="worker" && skl[sname[i]] >= 200) continue;
		me->set_skill(sname[i],skl[sname[i]] + 1);
		if (me->query_skill("bangjue", 1) > 200)
			me->set_skill("bangjue", 200);
		if (me->query_skill("begging", 1) > 200)
			me->set_skill("begging", 200);
		if (me->query_skill("stealing", 1) > 200)
			me->set_skill("stealing", 200);
		if (me->query_skill("dagou-zhen", 1) > 200)
			me->set_skill("dagou-zhen", 200);
		if (me->query_skill("checking", 1) > 200)
			me->set_skill("checking", 200);
/*
                if (me->query_skill("literate", 1) > me->query("int") * 10)
                        me->set_skill("literate", me->query("int") * 10);
*/
	}
/*
	for(i=0; i<sizeof(sname); i++){
		if( me->query_skill(skilllimit[i]) > lvllimit[i] )
			me->set_skill(skilllimit[i],lvllimit[i] );
	}
*/
	me->add("gb/bags",1);
	bag = bag + 1;
	me->add("max_neili", 15 * (bag));
	command("congra " + me->query("id"));

	if (bag < 8){
		command("say �ɵúã��ӽ��쿪ʼ�������ؤ��" + chinese_number(bag) + "�����ӣ��úøɣ�\n");
		me->set("title",sprintf("ؤ��%s%s������", fenduo, chinese_number(bag)));
	}
	else if (bag == 8){
		command("say �ɵúã��ӽ��쿪ʼ�������ؤ��" + chinese_number(bag) + "�����ӣ��úøɣ�\n");
		me->set("title",sprintf(YEL"ؤ��%s%s��������"NOR, fenduo, chinese_number(bag)));
	}
	else if (bag == 9){
		command("say �ɵúã��ӽ��쿪ʼ�������ؤ��"+ chinese_number(bag) + "�����ϣ��úøɣ�\n");
		me->set("title",sprintf(HIW"ؤ��%s������"NOR, chinese_number(bag)) );
	}
	return 1;
}
