#include <ansi.h>

string* names = ({
        "juechan shiren",
        "bichan shiren",
        "kuchan shiren",
        "kongchan shiren",
        "jichan shiren",
        "liaochan shiren",
        "mingchan shiren",
});
/*
int accept_object(object who, object ob,object me)
{
	mapping fam, my_fam, skl; 
        object fighter,room, monk;
	string *sname;
	int i,j;
        my_fam  = fighter->query("family");
	skl = fighter->query_skills();
	sname  = keys(skl);
	fighter = this_player();
        //me = this_object();
        if(!who->query_temp("baitie")){
                command("say ��İ����������ģ�����ת������ˡ���Ӵ���");
                return 1;
	}
        if(ob->query("name")=="����"){
        if (!(fam = this_player()->query("family")) 
           || fam["family_name"] != "������"){
                command("angry "+who->query("id"));
                command("say �ð����㹫Ȼ��ս���ɣ���������֪��������");
                command("follow"+who->query("id"));
                command("kill"+who->query("id"));
        return 1;
        }
          command("hmm"+this_player()->query("id"));
          for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 120) 
        return notify_fail((RANK_D->query_respect(this_player())) +
                "�����������������ԡ�");
                }

        if(fighter->query("pass_du"))
         return notify_fail(RANK_D->query_respect(fighter)+
                "��ʦ�������ϵļ��Ÿߵܣ��α�����������?\n");
        if( fighter->query("pass_xin") )
		return notify_fail(RANK_D->query_respect(fighter) + 
		"�������ڸ�ɮ���ɲ�Ҫ�����Ŀ������Ц��");

	if ( mapp(fam = fighter->query("family")) 
	&& fam["family_name"] == "������"
	&& fam["generation"] != (my_fam["generation"] + 3))
		return notify_fail(RANK_D->query_respect(fighter) + 
		"���ݲ��ϣ������ʸ��������С�");

        if ( (int)fighter->query("guilty") > 0 )
		return notify_fail(RANK_D->query_respect(fighter) + 
                "���۷����䣬�����������Ȼ�ȥ��ڰɣ�\n");

/*        if ( me->query("assigned_fighter") )
		return notify_fail(RANK_D->query_respect(fighter) + 
		"������������սʯ�˴������һ��ʱ�������ɡ�");
         command("say ����������ʥ������������֣����и�����һ�������
                      ���������϶����ܴ��ۡ�");
         command("say �˺����ǿ��������������Ա���Ϊ�ʹ�˵���λ���ǻ�
                      �ĳ����ղ��ܳ��ҷ�Ҹ�ɮ���͡�");
         command("say ��������������Ҳʵ������������֮������Ҳ�в��ٸ�ɮ��
                      �ͣ������������ޡ����ҷ�����������书����ĩ��"+
                      RANK_D->query_respect(this_player()) +"�αض�Ҫð�˴��գ�
                      �����Ծ���");
	say("\n����˵�����ðɣ���������ʯ����أ�������þͻ���Ϊ��(huadi)׼������ɡ�\n");
	me->set("assigned_fighter", fighter->query("id")); 		
	//if( !fighter->query_temp("xuannan-asked") )
	//say("\n�����ֵ���������ȥ��֪���������Ѵ�ʦ�����������м����������޺��������䳡���ϡ�\n");
        message_vision("\n���ƴ�ʦ�����뿪��\n\n", fighter);
         for(j=1; j<8; j++) 
         {
             if(!( room = find_object("/u/hunthu/shiting" + j)) )
              room = load_object("/u/hunthu/shiting" + j);
  		me->move(room);
		if( !objectp(monk = present(names[j-1], room) ))
		{
	        	me->move("/d/shaolin/xcping");
        	        message_vision("\n������ʦ���˹�����\n\n", fighter);
			return notify_fail("���ǶԲ���ʯͤ����ʯ�˶��ԣ�û�����д����ˡ�\n");	
		}

                message("vision", "\n���ƴ�ʦ���˹�������" + monk->query("name") + "�������һ�ơ�\n", room, monk);

                monk->move("/d/shaolin/hguangz1");
                message("vision", monk->query("name") + "�첽���˳�ȥ��\n", room, monk);
	}
	
        me->move("/d/shaolin/xcping");

        call_out("waiting", 1, me);
        command("nod"+fighter->query("id"));
        return 1;
} */

