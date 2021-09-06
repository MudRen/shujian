
inherit FIGHTER;
inherit F_UNIQUE;
#include <ansi.h>
//#include <skills_pfm.h>
void do_copy(object ob);
string *valid_types =
({
	"claw",
	"cuff",
	"finger",
	"hand",
	"leg",
	"strike",
});

void create()
{
	mapping name;
	int sex = random(3);
	name = RNAME_D->get_random_name(random(3));
	set_name(name["name"], name["id"]);
	set_name(query("name"), ({ query("id"),"dls dizi"}));
	set("gender", (sex?"����":"Ů��"));
	set("long", "�����ˣ��㾡����ȥȥ���壬ȴ����һƬģ����\n");
	set("age", 25+random(100));
	set("attitude", "peaceful");
	set("rank_info/rank","������");
	set("rank_info/self_rude","������");
	set("rank_info/self","С��");
	set("rank_info/rude","������");
	set("rank_info/respect","������");
	set("rank_info/color","HIW");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("max_qi", 500);
	set("max_jing", 500);
	set("eff_jingli",400);
	set("neili", 100);
	set("max_neili", 100);
	set("jiali", 20);
	set("combat_exp", 8000+random(500));
//һЩ�书�������趨��Ϊquestȡ�����������Ӹñ���
//Ŀǰ�趨������ʹ�õ���tanzhi-shentong��pfm qiankun
    set("quest_cancel",1);

	set_skill("force", 70);
	set_skill("dodge", 80);
	set_skill("unarmed", 70);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	set("inquiry", ([
		"name" : random(2)?"ʲô�����֣�":"�Ǻǣ��������Σ�������������ˡ�",
		"����" : random(2)?"ʲô�����֣�":"�Ǻǣ��������Σ�������������ˡ�",
		"��ʦ" : "��....��С��ע��һ��Ư�����������˰ɡ�",
    ]));

	setup();
	carry_object(ARMOR_D("shoes"))->wear();
	carry_object(ARMOR_D("changshan"))->wear();
}
init()
{
	int i,p;
    mapping pmap;
	object me=this_object();
	if(query("set_ok")) return;
	set("set_ok",1);
	pmap = me->query_skill_prepare();
	if (!pmap)
	{
		i=sizeof(valid_types);
		p=0;
		while (i--)
		{
			if (!me->query_skill(valid_types[i], 1)) continue;
			if (me->query_skill_mapped(valid_types[i]))continue;
			if(p>=2) continue;
			p=p+1;
			me->prepare_skill(valid_types[i], me->query_skill_mapped(valid_types[i]));
		}
	}	
	remove_call_out("dest");
	call_out("dest",120);
}
void die()
{
	object ob,me;
	object *obs;
	int i;
	ob=this_object();

    if(ob->query("kill_object") && ob->query("quest/level"))
	{
        me=ob->query("kill_object");
	}
	if(me && present(me,environment(ob)))
	{
		i=ob->query("quest/level");
		i=i*i;
		me->add_temp("quest/special/score",i);
		me->add("quest/special/score",i);
		tell_object(me,HIR"\n��ɹ��Ļ���"+ob->short(1)+HIR"����ý�������"+i+"��*_* \n"NOR);
		log_file("quest/SPECIAL", sprintf("%s(%s) ����¥�����÷���������%d�����飺%d��\n", me->name(1),me->query("id"),i,me->query("combat_exp")) );
	}
	obs = deep_inventory(ob);       
	obs = filter_array(obs,(:$1->query("imbued"):));
	i = sizeof(obs);
	while(i--)
	{
		obs[i]->move(environment(ob));
		message_vision(YEL"$N����һ"+obs[i]->query("unit")+obs[i]->name()+NOR+YEL"��\n"NOR,ob);
	}
	message_vision(HIY"\nͻȻһ���ɢ��$Nԭ��վ�ŵĵط���Ȼһ��ۼ�Ҳû�����¡�\n"HIM"�ղŵ�һ�����λð㣬ȫȻ�����ڷ��С�\n"NOR,this_object());
	destruct(this_object());
}
void unconcious()
{
  die();
}
void dest()
{
	message_vision(HIR"\nͻȻһ���ɢ��$Nԭ��վ�ŵĵط���Ȼһ��ۼ�Ҳû�����¡�"HIM"�ղŵ�һ�����λð㣬ȫȻ�����ڷ��С�\n"NOR,this_object());
	destruct(this_object());
}
void do_copy(object ob)
{
        object *inv;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i;
		string* u_pfm=({});		
        set_name(ob->name(), ({ ob->query("id")}) );
        set("title", ob->query("title") );
        set("long", ob->query("long") );
        set("gender", ob->query("gender") );
        set("per", ob->query("per") );
        set("age", ob->query("age") );
		set("family/family_name",ob->query("family/family_name"));
		set("family/master",ob->query("family/master"));
        set_temp("apply/damage",  30 + random(100) );
        set_temp("apply/attack",  30 + random(100) );
        set_temp("apply/armor",   30 + random(100) );

// copy skills

        if( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        set_skill(sname[i], skill_status[sname[i]]);
                }
        }

// copy skill maps

        if( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        map_skill(mname[i], map_status[mname[i]]);
                }
        }

// copy skill prepares

        if( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }

// copy weapon & armor

        inv = all_inventory(ob);
        i = sizeof(inv);
        while (i--) {
                if( inv[i]->query("weapon_prop/damage") > 100
                || inv[i]->query("unique")
                || inv[i]->query("imbued")
                || inv[i]->query("treasure")
                || inv[i]->query("armor_prop/armor") > 100 ) continue;
				inv[i]->set("copy_object",1);
                if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wield();
                        set("weapon", base_name(inv[i]));
                }
                if( inv[i]->query("armor_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                        set("armor", base_name(inv[i]));
                }
        }

        hp_status = ob->query_entire_dbase();

        set("str", hp_status["str"]);
        set("int", hp_status["int"]);
        set("con", hp_status["con"]);
        set("dex", hp_status["dex"]);

        set("max_qi",    hp_status["max_qi"]);
        set("eff_qi",    hp_status["max_qi"]);
        set("qi",        hp_status["max_qi"]);
        set("max_jing",  hp_status["max_jing"]);
        set("eff_jing",  hp_status["max_jing"]);
        set("jing",      hp_status["max_jing"]);
        set("max_neili", hp_status["max_neili"]);
        set("eff_jingli", hp_status["max_jingli"]);
        set("max_jingli", hp_status["max_jingli"]);
        set("jingli",     hp_status["max_jingli"]*2);
        set("neili",     hp_status["max_neili"]*2);
        set("jiali",     hp_status["jiali"]*2);
        if( query("jiali") > 200 ) set("jiali", 200 );
        set("combat_exp",hp_status["combat_exp"]);

		if(query("family/family_name")=="�䵱��")
		{
			u_pfm=u_pfm + ({(: exert_function, "yinyun" :)});             //������pfm:���ھ�
			u_pfm=u_pfm + ({(: exert_function, "taiji" :)});             //̫��
			u_pfm=u_pfm + ({(: perform_action, "dodge.zong" :)});         //������pfm:��   
			u_pfm=u_pfm + ({(: perform_action, "strike.bingdi" :)});  //��ɽ����pfm:��������
			u_pfm = u_pfm + ({(: perform_action, "cuff.ji" :)});				//̫��ȭpfm:��
			u_pfm = u_pfm + ({(: perform_action, "cuff.zhannian" :)});			//ճ�
			u_pfm = u_pfm + ({(: perform_action, "cuff.zhen" :)});				//��
			u_pfm = u_pfm + ({(: perform_action, "cuff.luanhuan" :)});			//�һ���
			u_pfm = u_pfm + ({(: perform_action, "cuff.yinyang" :)});			//������
			u_pfm = u_pfm + ({(: perform_action, "cuff.gangrou" :)});			//�����
			u_pfm = u_pfm + ({(: perform_action, "cuff.dongjing" :)});			//������
			u_pfm = u_pfm + ({(: perform_action, "cuff.an" :)});				//��
			u_pfm = u_pfm + ({(: perform_action, "sword.chan" :)});				//̫����pfm����
			u_pfm = u_pfm + ({(: perform_action, "sword.sanhuan" :)});			//��������
			u_pfm = u_pfm + ({(: perform_action, "sword.lian" :)});				//��
			set("wd/raozhi",1);
			u_pfm = u_pfm + ({(: perform_action, "sword.raozhi" :)});			//��ָ�ὣ
		}
		if(query("family/family_name")=="��ɽ��")
		{
			u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   //��������pfm������
			u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     //�ۺ�
			u_pfm=u_pfm + ({(: perform_action, "hand.junji" :)});        //������pfm������
			u_pfm=u_pfm + ({(: perform_action, "hand.yinyang" :)});      //����
			u_pfm=u_pfm + ({(: perform_action, "whip.luan" :)});          //������pfm����
			u_pfm = u_pfm + ({(: perform_action, "strike.hanbing" :)});     //��������pfm������
			u_pfm = u_pfm + ({(: perform_action, "sword.feiwu" :)});        	//��ɽ����pfm������
			u_pfm = u_pfm + ({(: perform_action, "sword.leiting" :)});			//����һ��
			u_pfm = u_pfm + ({(: perform_action, "sword.longfeng" :)});			//����	
			u_pfm = u_pfm + ({(: perform_action, "sword.songyang" :)});			//����
		}
		if(query("family/family_name")=="ؤ��")
		{
			u_pfm=u_pfm + ({(: exert_function, "huntian" :)});          //��������pfm��powerup
			u_pfm=u_pfm + ({(: perform_action, "whip.huixuan" :)});       //�ط��pfm���ط�
			u_pfm=u_pfm + ({(: perform_action, "staff.feizhi" :)});       //��������pfm����������	
			u_pfm = u_pfm + ({(: perform_action, "strike.paiyun" :)});         //������pfm������˫��
			u_pfm = u_pfm + ({(: perform_action, "strike.xiao" :)});		//Х
			u_pfm = u_pfm + ({(: perform_action, "strike.kanglong" :)});	//�����޻�
			u_pfm = u_pfm + ({(: perform_action, "stick.chan" :)});       	//�򹷰���pfm����
			u_pfm = u_pfm + ({(: perform_action, "stick.chuo" :)});			//��
			u_pfm = u_pfm + ({(: perform_action, "stick.shuangjue" :)});	//����˫��
			u_pfm = u_pfm + ({(: perform_action, "stick.tiao" :)});			//��
			u_pfm = u_pfm + ({(: perform_action, "stick.zhuan" :)});		//ת
			u_pfm = u_pfm + ({(: perform_action, "stick.wugou" :)});		//�����޹�
		}
		if(query("family/family_name")=="��ɽ��")
		{
			u_pfm=u_pfm + ({(: exert_function, "zixia" :)});            //��ϼ��pfm��zixia    
			u_pfm=u_pfm + ({(: perform_action, "blade.sanshenfeng" :)});       //�����ǵ���pfm�����������
			u_pfm=u_pfm + ({(: perform_action, "strike.wuji" :)});       //��Ԫ��pfm����Ԫ�޼�
			u_pfm = u_pfm + ({(: perform_action, "sword.feijian" :)});     	//��ɽ����pfm���ɽ�
			u_pfm = u_pfm + ({(: perform_action, "sword.junzi" :)});		//����
			u_pfm = u_pfm + ({(: perform_action, "sword.kuaijian" :)});		//�콣
			u_pfm = u_pfm + ({(: perform_action, "sword.lianhuan" :)});		//����
			u_pfm = u_pfm + ({(: perform_action, "sword.sanqingfeng" :)});	//�����
			u_pfm = u_pfm + ({(: perform_action, "sword.shijiushi" :)});	//ʮ��ʽ
			u_pfm = u_pfm + ({(: perform_action, "sword.shunv" :)});		//��Ů
			u_pfm = u_pfm + ({(: perform_action, "sword.wushuang" :)});		//��˫
			u_pfm = u_pfm + ({(: perform_action, "sword.xiyi" :)});			//ϣ��
			u_pfm = u_pfm + ({(: perform_action, "sword.yangwu" :)});		//����
			u_pfm = u_pfm + ({(: perform_action, "sword.kuangfeng" :)});    //���¾Ž�pfm�����
			u_pfm = u_pfm + ({(: perform_action, "sword.pobian" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.pojian" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.pozhang" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.poqi" :)});	
			u_pfm = u_pfm + ({(: perform_action, "sword.poqiang" :)});	
			u_pfm = u_pfm + ({(: perform_action, "sword.posuo" :)});		
			u_pfm = u_pfm + ({(: perform_action, "sword.zongjue" :)});		//�ܾ�

		}
		if(query("family/family_name")=="���ư�")
		{
			u_pfm=u_pfm + ({(: exert_function, "focus" :)});          //��������pfm��focus
			u_pfm=u_pfm + ({(: perform_action, "dodge.piao" :)});     //ˮ��Ưpfm:Ư
			u_pfm = u_pfm + ({(: perform_action, "strike.duoming" :)});     //�����Ʒ�pfm��������צ
			u_pfm = u_pfm + ({(: perform_action, "strike.heisha" :)});     //�����Ʒ�pfm���� ɰ ��
			u_pfm = u_pfm + ({(: perform_action, "strike.heyi" :)});     //�����Ʒ�pfm��������һ
			u_pfm = u_pfm + ({(: perform_action, "strike.honglei" :)});     //�����Ʒ�pfm������˫��
			u_pfm = u_pfm + ({(: perform_action, "strike.judu" :)});     //�����Ʒ�pfm����    ��
			u_pfm = u_pfm + ({(: perform_action, "strike.pangen" :)});     //�����Ʒ�pfm�������̸�
			u_pfm = u_pfm + ({(: perform_action, "strike.pushan" :)});     //�����Ʒ�pfm����������
			u_pfm = u_pfm + ({(: perform_action, "strike.qinna" :)});     //�����Ʒ�pfm����������
			u_pfm = u_pfm + ({(: perform_action, "strike.rubairen" :)});     //�����Ʒ�pfm���� �� ��
			u_pfm = u_pfm + ({(: perform_action, "strike.tianlei" :)});     //�����Ʒ�pfm���� �� ��
			u_pfm = u_pfm + ({(: perform_action, "strike.xuanfeng" :)});     //�����Ʒ�pfm���������
			u_pfm = u_pfm + ({(: perform_action, "strike.zhangdao" :)});     //�����Ʒ�pfm�������Ƶ�
			u_pfm = u_pfm + ({(: perform_action, "strike.tiezhang" :)});     //�����Ʒ�pfm������
			u_pfm=u_pfm + ({(: perform_action, "blade.daozhang" :)});   //��Ҷ����pfm������
			u_pfm=u_pfm + ({(: perform_action, "axe.lihun" :)});  		//���츫pfm�����
		}
		if(query("family/family_name")=="������")
		{
			u_pfm=u_pfm + ({(: exert_function, "longxiang" :)});   //���������pfm������
			u_pfm=u_pfm + ({(: exert_function, "shield" :)});      //����
			u_pfm=u_pfm + ({(: perform_action, "hand.tianyin" :)});  //����ӡpfm����������ӡ

			u_pfm = u_pfm + ({(: perform_action, "strike.fen" :)});     //���浶pfm����
			u_pfm = u_pfm + ({(: perform_action, "strike.ran" :)});     //���浶pfm����
			u_pfm = u_pfm + ({(: perform_action, "strike.daoqi" :)});     //���浶pfm����
			u_pfm = u_pfm + ({(: perform_action, "blade.jixue" :)});        	//pfm ��Ѫ
			u_pfm = u_pfm + ({(: perform_action, "blade.shendao" :)});			//�񵶴���
			u_pfm = u_pfm + ({(: perform_action, "hammer.wushuai" :)});        	//������˥
			u_pfm = u_pfm + ({(: perform_action, "hammer.dazhuan" :)});			//��ת
		}
		if(query("family/family_name")=="��Ĺ��")
		{
			u_pfm=u_pfm + ({(: exert_function, "xinjing" :)});  //��Ů�ľ�pfm��xinjing
			u_pfm = u_pfm + ({(: perform_action, "cuff.shexin" :)});		//��Ůȭ��pfm:����
			u_pfm=u_pfm + ({(: perform_action, "sword.suxin" :)});      //��Ů���Ľ�pfm������
			u_pfm=u_pfm + ({(: perform_action, "sword.qixing" :)});     	//ȫ�潣��pfm�����Ǿ۶�
			u_pfm=u_pfm + ({(: perform_action, "sword.sanqing" :)});   	    //�����
			u_pfm = u_pfm + ({(: perform_action, "strike.anran" :)});     //��Ȼ������pfm����Ȼ
			u_pfm = u_pfm + ({(: perform_action, "strike.jishi" :)});     //��Ȼ������pfm������
			u_pfm = u_pfm + ({(: perform_action, "strike.xiaohun" :)});     //��Ȼ������pfm������
			u_pfm = u_pfm + ({(: perform_action, "sword.haichao" :)});        	//����pfm������
			u_pfm = u_pfm + ({(: perform_action, "sword.wujian" :)});			//�޽�
			set("gmsanwu",1);
			u_pfm = u_pfm + ({(: perform_action, "whip.sanwu" :)});        	//��������pfm������������
		}
		if(query("family/family_name")=="����Ľ��")
		{		
			u_pfm=u_pfm + ({(: exert_function, "shenyuan" :)});   		//��Ԫ��pfm����Ԫ
			u_pfm=u_pfm + ({(: perform_action, "parry.xingyi" :)});     //��ת����pfm������
			u_pfm=u_pfm + ({(: perform_action, "strike.riyue" :)});        //������pfm������ͬ��
			u_pfm = u_pfm + ({(: perform_action, "finger.ci" :)});     //�κ�ָpfm����
			u_pfm=u_pfm + ({(: perform_action, "blade.daoying" :)});     //Ľ�ݵ���pfm����Ӱ��
			u_pfm = u_pfm + ({(: perform_action, "sword.lianhuan" :)});        	//Ľ�ݽ���pfm������
			u_pfm = u_pfm + ({(: perform_action, "sword.sanhua" :)});			//ɢ��
		}
		if(query("family/family_name")=="������")
		{
			u_pfm=u_pfm + ({(: exert_function, "wudi" :)});   		//������pfm���޵�
			u_pfm=u_pfm + ({(: perform_action, "whip.chan" :)});          //���߱޷�pfm������
			u_pfm=u_pfm + ({(: perform_action, "whip.sandou" :)});        //���߱޷�pfm������
			u_pfm = u_pfm + ({(: perform_action, "strike.bujue" :)});     //��������pfm������
			u_pfm = u_pfm + ({(: perform_action, "dagger.diqing" :)});        	//����ذ��pfm�����ཱུ��
			u_pfm = u_pfm + ({(: perform_action, "dagger.feiyan" :)});			//�������
			u_pfm = u_pfm + ({(: perform_action, "dagger.guifei" :)});			//��������	
			u_pfm = u_pfm + ({(: perform_action, "dagger.luda" :)});			//³�����
			u_pfm = u_pfm + ({(: perform_action, "dagger.xiaolian" :)});		//С�����
			u_pfm = u_pfm + ({(: perform_action, "dagger.zixu" :)});			//����ٶ�
		}
		if(query("family/family_name")=="������")
		{
			u_pfm=u_pfm + ({(: exert_function, "judu" :)});   //�۶�
			u_pfm = u_pfm + ({(: perform_action, "staff.feizhi" :)});        	//��ɽ�ȷ�pfm������
			u_pfm = u_pfm + ({(: perform_action, "strike.biyan" :)});     //������pfm������
			u_pfm = u_pfm + ({(: perform_action, "strike.huoqiang" :)});     //������pfm����ǽ
			u_pfm = u_pfm + ({(: perform_action, "strike.huoqiu" :)});     //������pfm������
			u_pfm = u_pfm + ({(: perform_action, "strike.yinhuo" :)});     //������pfm������
		}
		if(query("family/family_name")=="��ü��")
		{
			u_pfm=u_pfm + ({(: exert_function, "fengyun" :)});   //�ټ�ʮ��ׯpfm������
			u_pfm=u_pfm + ({(: exert_function, "riyue" :)});	 //����
			u_pfm=u_pfm + ({(: exert_function, "tiandi" :)});    //��� 
			u_pfm=u_pfm + ({(: exert_function, "wuwo" :)});      //����
			u_pfm=u_pfm + ({(: exert_function, "yinyang" :)});   //����  
			if(random(5)==1)
			u_pfm=u_pfm + ({(: exert_function, "youming" :)});   //��ڤ  
			u_pfm=u_pfm + ({(: exert_function, "zhixin" :)});    //֮�� 
			u_pfm=u_pfm + ({(: perform_action, "blade.feiyang" :)});          //���е���pfm������
			u_pfm=u_pfm + ({(: perform_action, "blade.huanying" :)});         //���е���pfm����Ӱ
			u_pfm = u_pfm + ({(: perform_action, "sword.jue" :)});        		//�ط������pfm����
			u_pfm = u_pfm + ({(: perform_action, "sword.liaoyuan" :)});			//��ԭ
			u_pfm = u_pfm + ({(: perform_action, "sword.mie" :)});				//��
			u_pfm = u_pfm + ({(: perform_action, "hand.foguang" :)});     //���־�ʽpfm������

		}
		if(query("family/family_name")=="����")
		{	
			u_pfm=u_pfm + ({(: exert_function, "tougu" :)});	 //ʥ����pfm:͸��
			u_pfm=u_pfm + ({(: exert_function, "yinfeng" :)});	 //����		
			u_pfm = u_pfm + ({(: perform_action, "strike.xixue" :)});		//��������pfm:��Ѫ
			u_pfm = u_pfm + ({(: perform_action, "blade.shenghuo" :)});		 //���浶pfm:ʥ��
			u_pfm=u_pfm + ({(: exert_function, "powerup" :)});	 //powerup	
			u_pfm = u_pfm + ({(: perform_action, "cuff.qishang" :)});     //����ȭpfm������
			u_pfm = u_pfm + ({(: perform_action, "cuff.duanhun" :)});     //����ȭpfm���ϻ�
			u_pfm = u_pfm + ({(: perform_action, "dagger.duo" :)});        	//ʥ���pfm����
			u_pfm = u_pfm + ({(: perform_action, "dagger.ji" :)});			//��
			u_pfm = u_pfm + ({(: perform_action, "dagger.tisha" :)});			//��ɳ	
			u_pfm = u_pfm + ({(: perform_action, "dagger.xinmo" :)});			//��ħ
		}
		if(query("family/family_name")=="�һ���")
		{
			u_pfm=u_pfm + ({(: exert_function, "maze" :)});     //����
			u_pfm=u_pfm + ({(: exert_function, "qimen" :)});     //��������
			u_pfm=u_pfm + ({(: perform_action, "dodge.wuzhuan" :)});			//�沨����pfm:��ת
			u_pfm=u_pfm + ({(: perform_action, "strike.pikong" :)});        //��Ӣ����pfm������
			u_pfm=u_pfm + ({(: perform_action, "leg.kuangfeng" :)});        //����ɨҶ��pfm�����
			u_pfm = u_pfm + ({(: perform_action, "sword.feiying" :)});        	//���｣��pfm����Ӱ
			u_pfm = u_pfm + ({(: perform_action, "sword.qimen" :)});			//����
			u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)});     //��ָ��ͨpfm��Ǭ��һָ
			u_pfm = u_pfm + ({(: perform_action, "finger.shentong" :)});     //��ָ��ͨpfm����ͨ
			u_pfm = u_pfm + ({(: perform_action, "sword.feiying" :)});        	//���｣��pfm����Ӱ
			u_pfm = u_pfm + ({(: perform_action, "sword.qimen" :)});			//����
		}
		if(query("family/family_name")=="������")
		{		
			u_pfm=u_pfm + ({(: exert_function, "xinjing" :)});   
			u_pfm = u_pfm + ({(: perform_action, "finger.sandie" :)}); 			//һ��ָpfm����������
			u_pfm = u_pfm + ({(: perform_action, "finger.yizhisanmai" :)}); 	//һָ����
			u_pfm=u_pfm + ({(: perform_action, "sword.fenglei" :)});          	//�μҽ���pfm�������Ļ�
			u_pfm = u_pfm + ({(: exert_function, "rong" :)}); 					//��������pfm����
			u_pfm = u_pfm + ({(: perform_action, "strike.jiuchong" :)});		//������
			u_pfm = u_pfm + ({(: perform_action, "whip.cibei" :)});        		//�Ⱥ���pfm���ȱ��־�
			u_pfm = u_pfm + ({(: perform_action, "axe.jingtian" :)});        	//�̸���ḫpfm��������Ƹ�
		}
		if(query("family/family_name")=="������")
		{	
			u_pfm=u_pfm + ({(: exert_function, "jingang" :)});   							//�׽pfm����ղ�������
			u_pfm = u_pfm + ({(: perform_action, "strike.sanhua" :)});
			u_pfm = u_pfm + ({(: perform_action, "finger.fuxue" :)});    
			u_pfm = u_pfm + ({(: perform_action, "finger.wofo" :)});    		//һָ��pfm������ҷ�
			u_pfm = u_pfm + ({(: perform_action, "finger.qiankun" :)}); 		//һָǬ��
			u_pfm = u_pfm + ({(: perform_action, "claw.canyun" :)}); 			//��צ��pfm��������
			u_pfm = u_pfm + ({(: perform_action, "hand.qianshou" :)});    		//����ǧҶ��pfm��ǧ������
			u_pfm = u_pfm + ({(: perform_action, "leg.ruying" :)});    			//��Ӱ������pfm����Ӱ����
			u_pfm = u_pfm + ({(: perform_action, "strike.chaodu" :)}); 			//������pfm������������
			if(random(5)==1)
				u_pfm = u_pfm + ({(: perform_action, "strike.yipai" :)});   		//һ����ɢ
			u_pfm = u_pfm + ({(: perform_action, "cuff.fumo" :)});    			//����ȭpfm����շ�ħ
			u_pfm = u_pfm + ({(: perform_action, "whip.fumoquan" :)});        	//���±޷�pfm����շ�ħȦ
			u_pfm = u_pfm + ({(: perform_action, "whip.chanrao" :)});        	//������� 
			u_pfm = u_pfm + ({(: perform_action, "blade.fentian" :)});			//ȼľ����pfm���ٻ����
			u_pfm = u_pfm + ({(: perform_action, "blade.fenwo" :)});        	//����
			u_pfm = u_pfm + ({(: perform_action, "club.leidong" :)});			//Τ����pfm���׶�����
			u_pfm = u_pfm + ({(: perform_action, "club.chaodu" :)});        	//���ȼ��� 
		}
		if(query("family/family_name")=="������")
		{
			u_pfm=u_pfm + ({(: exert_function, "xuantian" :)});   							//�����޼���
			u_pfm=u_pfm + ({(: exert_function, "wuji" :)});     							//
			u_pfm = u_pfm + ({(: perform_action, "strike.diezhang" :)});     //�����Ʒ�pfm����ɽ����
			u_pfm = u_pfm + ({(: perform_action, "sword.xunlei" :)});     //�����Ʒ�pfm����ɽ����
			u_pfm = u_pfm + ({(: perform_action, "sword.hundun" :)});     //�����Ʒ�pfm����ɽ����
			u_pfm = u_pfm + ({(: perform_action, "leg.chuanyun" :)});     //�����Ʒ�pfm����ɽ����
		}
		if(query("family/family_name")=="�����澭����")
		{
			u_pfm=u_pfm + ({(: exert_function, "yihuen" :)});   
			u_pfm=u_pfm + ({(: exert_function, "zongjue" :)});   							//�����ܾ�
			u_pfm=u_pfm + ({(: perform_action, "dodge.huanyinbu" :)});      				//������pfm��������
			u_pfm=u_pfm + ({(: perform_action, "claw.jiuyin" :)});			//�����׹�צpfm����������צ
			u_pfm=u_pfm + ({(: perform_action, "strike.cuixin" :)});
			u_pfm=u_pfm + ({(: perform_action, "whip.chanrao" :)});   	   //����������pfm�����ƾ�			
			u_pfm=u_pfm + ({(: perform_action, "whip.feilong" :)});        //����  
			u_pfm = u_pfm + ({(: perform_action, "strike.shenzhang" :)});   //��������pfm�����ƶ���
			u_pfm = u_pfm + ({(: perform_action, "strike.yinyang" :)});		//����˫��   
			u_pfm = u_pfm + ({(: perform_action, "strike.sanjue" :)});      //������צpfm����������צ
			u_pfm = u_pfm + ({(: perform_action, "sword.xuanyin" :)});      //��������pfm�������� 	
			u_pfm = u_pfm + ({(: perform_action, "sword.zhan" :)});			//ն�־�	
		}
		if(query("family/family_name")=="��󡹦����")
		{
			set("oyf/hamagong",3);
			u_pfm = u_pfm + ({(: perform_action, "strike.hama" :)});        	
			u_pfm = u_pfm + ({(: exert_function, "nizhuan" :)});        	
		}
		if(query("family/family_name")=="�������ܵĴ���")
		{	
			u_pfm=u_pfm + ({(: exert_function, "hanbing" :)});   //��������pfm������
			u_pfm=u_pfm + ({(: exert_function, "juhan" :)});     //�ۺ�
			u_pfm = u_pfm + ({(: perform_action, "sword.cimu" :)});        	
			u_pfm = u_pfm + ({(: perform_action, "dodge.feiying" :)});        	
			u_pfm = u_pfm + ({(: perform_action, "sword.jue" :)});        	
		}
		if(query("family/family_name")=="���߽����Ĵ���")
		{
			u_pfm = u_pfm + ({(: perform_action, "sword.kuangwu" :)});        	
     	}
		set("chat_chance_combat", 100);
		set("chat_msg_combat", u_pfm);

}
