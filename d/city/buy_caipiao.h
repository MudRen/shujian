//���Ʊר��  by lsxk@hsbbs 2007/9/25
string Random_Source(int);

string *s_char = ({ "1","2","3","4","5","6","7","8","9","0",
"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
"~","!","@","#","$","%","^","&","*"});

string This_Source = Random_Source(SIZE_OF_SOURCE);

string Random_Source(int i)
{
    string str, p, file_msg;
    int j;
    object obj;

    if(objectp(obj=load_object("/log/cpTag.c"))){
        delete("no_buy");
        str = obj->query("caipiao_id");
        destruct(obj);
        message("system",HIY"\n\n���齣���ʡ���"+HIG+"�����齣���ʱ�ѡ��Ϊ��"+HIW+str+HIG+" ���������ϲ�����к�ȥ�������Ĺ���\n\n"NOR, users());
        return str;
    }

    for (j = 0;j<i;j++)
    {
        p = s_char[random(sizeof(s_char))];
        if(!str)
             str = p;
        else
             str = str + " " + p;

        s_char -= ({p});
    }

    s_char = ({ "1","2","3","4","5","6","7","8","9","0",
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
    "~","!","@","#","$","%","^","&","*"});

    delete("no_buy");
     message("system",HIY"\n\n���齣���ʡ���"+HIG+"�����齣���ʱ�ѡ��Ϊ��"+HIW+str+HIG+" ���������ϲ�����к�ȥ�������Ĺ���\n\n"NOR, users());

    file_msg = sprintf("// ���ʿ�����ű�Ǳ���! \n");
    file_msg += "inherit ROOM;\n";
    file_msg += "void create()\n";
    file_msg += "{\n";
    file_msg += sprintf("\tset(\"short\", \"���ʱ��\");\n");
    file_msg +=sprintf("\tset(\"caipiao_id\",\"%s\");\n",str);
    file_msg +="\tsetup();\n";
    file_msg +="}\n";

    rm("/log/cpTag.c");
    assure_file("/log/cpTag.c");
    if( write_file( "/log/cpTag.c",file_msg,1) != 1 ){
            write("�޷�д���ļ�����֪ͨ������ʦ��\n");
    }
    return str;
}

int buy_caipiao(string arg)
{
    int k;
    string strMyCP, huobi, count;
    object me = this_player();
    object cp;

    if(!arg) return notify_fail("��Ҫ��ʲô?\n"NOR);

    if(query("no_buy"))
        return notify_fail("�����ǶԽ�ʱ�䣬��ȴ�ϵͳ����������Ϣ����������\n"NOR);

    if(me->query("caipiao_id")!=This_Source){
        me->delete("caipiao");
        me->delete("caipiao_id");
        me->delete("caipiao_zhongjiang_list");
        me->delete("caipiao_shot");
        tell_object(me, "ϵͳ��������������ǰδ�Խ��Ĳ�Ʊ���Ѿ��Զ������\n");
    }
    if(sscanf(arg, "%s with %s", strMyCP, huobi)){
        if( huobi != "ͨ��" && huobi != "�ƽ�")
            return notify_fail(HIG"����ݡ�"+HIR+"buy ����Ҫ��������� with [�ƽ�|ͨ��]"+HIG+"���ĸ�ʽ����������!\n"NOR);
    }
    else return notify_fail(HIG"��ʽ��������ݡ�"+HIR+"buy ����Ҫ��������� with [�ƽ�]"+HIG+"���ĸ�ʽ����������!\n"NOR);

    if(strMyCP!="random" && sizeof(strMyCP)!=(SIZE_OF_SOURCE*2-SIZE_OF_SOURCE/2-1))
        return notify_fail("�����������ų��Ȳ��ԣ���ȷ���������"+chinese_number(SIZE_OF_SOURCE)+"λ���ȵĺ���,����ÿ����λ�á�-���������ӣ�\n");

    if(strMyCP=="random")
        strMyCP = cp_kaijiang(1);

    for(k=0;k<sizeof(me->query("caipiao"));k++)
        if(strMyCP == me->query("caipiao/��"+chinese_number(k+1)+"��/my_caipiao"))
            return notify_fail("���Ѿ������������ˣ������ظ�����\n");

    if(huobi=="ͨ��"){
        if((int)me->query("SJ_Credit")<CREDIT_COST)
            return notify_fail("���ͨ�������������޷����룡\n");

        me->add("SJ_Credit",-CREDIT_COST);
        tell_object(me, HIY"������"+chinese_number(CREDIT_COST)+"���齣ͨ�������������Ϊ��"+strMyCP+" �Ĳ�Ʊ��\n"NOR);
        tell_object(me, HIG"����ɹ������עϵͳ������Ϣ��ף�����ˣ�\n"NOR);
    }

    if(huobi=="�ƽ�"){
        if((int)me->query("balance")<GOLD_COST)
            return notify_fail("��Ļƽ������������޷�����!\n");

        me->add("balance",-GOLD_COST);
        tell_object(me, HIY"������"+chinese_number(GOLD_COST/10000)+"���ƽ𣬹��������Ϊ��"+strMyCP+" �Ĳ�Ʊ��\n"NOR);
        tell_object(me, HIG"����ɹ������עϵͳ������Ϣ��ף�����ˣ�\n"NOR);
    }

    count = chinese_number(sizeof(me->query("caipiao"))+1);
    me->set("caipiao/��"+count+"��/time",time());
    me->set("caipiao/��"+count+"��/my_caipiao",strMyCP);
    me->set("caipiao/��"+count+"��/huobi",huobi);
    me->set("caipiao_id",This_Source);

    if(!present("cai piao",me)){
        cp = new(__DIR__"obj/caipiao");
        cp->move(me);
    }

    return 1;
}

