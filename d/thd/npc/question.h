int questions(object me)
{
	string answer;
	if (me->query_temp("jyquest")!=4){
		command("?");
		return 1;
	}
	if (me->query_temp("jiuyin/question")>9) {
		command("admire");
		command("say ԭ��������ͬ�����˰���");
		command("xixi");
//����Ҫ 4 ����ܹ��أ���������� 10 �����ϣ��͸�һ�� karma bonus
//		me->add_temp("apply/karma",5);
		return 1; 
	}
	command("hehe");
	command("say ע�������ˣ�");
	message_vision(HIR"�� answer ���ش𣬻ش���ʹ��ƴ�����룬��Ҫ�ú��֡�\n"NOR,me);
	switch (random(30)) {
		case 0:
			command("say ��ȫ��̵��ڹ��ķ���ʲô��");
			answer = "xiantian-gong";
			break;
		case 1:
			command("say ����а��������ָ����ʲô��");
			answer = "tanzhi-shentong";
			break;
		case 2:
			command("say �μ�������ָΪ���Ľ�������ʲô���֣�");
			answer = "liumai-shenjian";
			break;
		case 3:
			command("say ���ư�������Ṧ�ǣ�");
			answer = "shuishangpiao";
			break;
		case 4:
			command("say ��������ͷ�İ����ǽ���ʲô��");
			answer = "hansha-sheying";
			break;
		case 5:
			command("say �϶��������ڹ���ʲô��");
			answer = "hamagong";
			break;
		case 6:
			command("say �Ͻл��͹��ֵܶ�����Ʒ���ʲô��");
			answer = "xianglong-zhang";
			break;
		case 7:
			command("say ���ֺ����ǵ��ڹ���ʲô��");
			answer = "yijin-jing";
			break;
		case 8:
			command("say ���ҵĽ�����ʲô��");
			answer = "huifeng-jian";
			break;
		case 9:
			command("say �䵱����ͷ������������ȭ����ʲô���֣�");
			answer = "taiji-quan";
			break;
		case 10:
			command("say �������޼���С�ӵ��ڹ���ʲô��");
			answer = "jiuyang-shengong";
			break;
		case 11:
			command("say �����ɶ������õĹ�����ʲô��");
			answer = "huagong-dafa";
			break;
		case 12:
			command("say Ľ�ݼҵļҴ������мܼ����ǣ�");
			answer = "douzhuan-xingyi";
			break;
		case 13:
			command("say ����ǰ������������ʲô���������߻�����ģ�");
			answer = "qiankun-danuoyi";
			break;
		case 14:
			command("say ����а���������������ڹ�����������ڹ��������ǣ�");
			answer = "bihai-chaosheng";
			break;
		case 15:
			command("say �����ɾ���ѩ�˵Ľ�����ʲô���ƣ�");
			answer = "jinshe-jianfa";
			break;
		case 16:
			command("say ���ֽ���������ʹ�˾��Ӿ�����������������ʲô��");
			answer = "pixie-jian";
			break;
		case 17:
			command("say ��ɽ���ڵ���ɽ֮����ʲô��");
			answer = "zixia-gong";
			break;
		case 18:
			command("say ������ͯ���Դ�ȭ����ʲô����");
			answer = "kongming-quan";
			break;
		case 19:
			command("say ��ɽ���ڵĸ߼������ǣ�");
			answer = "dugu-jiujian";
			break;
		case 20:
			command("say ��Ĺ�ɵ��ڹ��ķ���ʲô��");
			answer = "yunu-xinjing";
			break;
		case 21:
			command("say ���������С�ӽ��ҵ��Ʒ�����ʲô���ƣ�");
			answer = "anran-zhang";
			break;
		case 22:
			command("say һ�ƴ�ʦ�����־�ѧ��ʲô��");
			answer = "yiyang-zhi";
			break;
		case 23:
			command("say �Ͻл��̻�����СѾͷ����ʲôȭ����");
			answer = "xiaoyaoyou";
			break;
		case 24:
			command("say ��Ĺһ�ɵ�����ȭ������ʲô���ƣ�");
			answer = "mainu-quan";
			break;
		case 25:
			command("say ����а���˽������ָ��ͨ��������ʲô�书��");
			answer = "yuxiao-jian";
			break;
		case 26:
			command("say ���õĸ�������ʲô��");
			answer = "niqiugong";
			break;
		case 27:
			command("say ���صļҴ��ַ���ʲô���֣�");
			answer = "lanhua-shou";
			break;
		case 28:
			command("say �һ��Ŀ�����Ҫ��ʲô������ɨҶ�����ʩչ��");
			answer = "luoying-zhang";
			break;
		case 29:
			command("say ���ҵ����ʦ̫���������ֹ������޼ɴ�ĵ��ز���");
			answer = "jieshou-jiushi";
			break;
	}
	this_object()->set("answer",answer);
	return 1;
}

int do_answer(string arg)
{
	object me = this_player();
	if (me->query_temp("jyquest")!=4)
		return notify_fail("ʲô��\n");
	if (!arg)
		return notify_fail("��Ҫ�ش�ʲô��\n");
	if (arg != this_object()->query("answer")) {
		command("say ��");
		command("papaya " + me->query("id")); 
	}
	else {
		command("say �������е�ͷ���");
		command("praise " + me->query("id"));
		command("say ����һ��ɡ�");
//		if (me->query_temp("jiuyin/question")>4)
//			me->add_temp("apply/karma",1);
		me->add_temp("jiuyin/question",1); 
	}
	call_out("questions", 1, me);
	return 1;
}
