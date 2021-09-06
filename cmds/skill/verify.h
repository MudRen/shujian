//      Tbh ��������
//      HBRED   HBGRN   HBYEL   HBBLU   HBMAG   HBCYN   HBWHT

#include <ansi.h>

mapping exert_names = ([
//  �˻����Ϲ�
        "bahuang-liuhe/bahuang":HBRED+HIW"���˻����ϡ�"NOR,
        "bahuang-liuhe/chuanyin":RED"������"NOR,
        "bahuang-liuhe/duzun":        HIG"��"HIR"Ψ�Ҷ���"HIG"��"NOR,

//  ��ڤ��
        "beiming-shengong/beiming":             BLU"��ڤ��"NOR,
        "beiming-shengong/huti":HBCYN+HIG"��ڤ����"NOR,
        "beiming-shengong/jiedu":HIG"�ⶾ��"NOR,
        "beiming-shengong/shengsifu":                  HIR"��"BLU" �� "WHT"��"NOR,
        "beiming-shengong/shougong":                  BLU"�չ���"NOR,

//  �̺�������        
        "bihai-chaosheng/cuidu":HIW"��    ��"NOR,
        "bihai-chaosheng/zhanbu":HIG"ռ �� ��"NOR,
        "bihai-chaosheng/lifeheal":HIW"��������"NOR,
        "bihai-chaosheng/maze":HIY"�����Ի���"NOR,
        "bihai-chaosheng/play":HIM"��    ��"NOR,
        "bihai-chaosheng/qimen":HIW"���Ű���"NOR,

//  ������        
        "dulong-dafa/jiedu":HIW"��    ��"NOR,
        "dulong-dafa/shougong":CYN"��    ��"NOR,
        "dulong-dafa/wudi":RED"�޵д�"NOR,
        "dulong-dafa/shexin":HIR"��    ��"NOR,

//  ��ü������        
//        "emei-jiuyang/heal":HIW"��������"NOR,
//        "emei-jiuyang/lifeheal":HIW"��������"NOR,
//        "emei-jiuyang/powerup":HIY"���Ҿ�����"NOR,

//  ��Ԫ���ɷ�        
        "guiyuan-tunafa/focus":HBBLU"��    ��"NOR,
//        "guiyuan-tunafa/lifeheal":HIY"��������"NOR,

//  ��������        
        "hanbing-zhenqi/hanbing":HIW"�� �� ��"NOR,
        "hanbing-zhenqi/juhan":HIW"��    ��"NOR,
        "hanbing-zhenqi/liaodu":HIW"��    ��"NOR,

//  ������
        "huagong-dafa/duwu":HIB"��    ��"NOR,
        "huagong-dafa/huadu":BLU"��    ��"NOR,
        "huagong-dafa/huagong":BLU"��    ��"NOR,
        "huagong-dafa/huajing":HIB"��    ��"NOR,
        "huagong-dafa/judu":BLU"�۶�����"NOR,
        "huagong-dafa/liaodu":HIB"��    ��"NOR,

// ��Ԫһ��
        "hunyuan-yiqi/heal":HIW"��������"NOR,
        "hunyuan-yiqi/lifeheal":HIW"��������"NOR,
        "hunyuan-yiqi/roar":HIY"ʨ �� ��"NOR,
        
/*        "hunyuan-gong/jianmang":                MAG"������â"NOR,
        "hunyuan-gong/ningshen":                MAG"��������"NOR,
        "hunyuan-gong/lifeforce":               MAG"��������"NOR,
        "hunyuan-gong/lifeheal":                MAG"�ơ�����"NOR,
        "hunyuan-gong/zixia":                   MAG"�ϡ���ϼ"NOR, */

//  ��������        
        "huntian-qigong/huntian":HIR"��    ��"NOR,
        "huntian-qigong/shentong":HIW"��    ͨ"NOR,
        "huntian-qigong/powerup":HIR"��������"NOR,
        "huntian-qigong/shougong":GRN"��    ��"NOR,

/*        "huagong-dafa/heal":                    RED"��������"NOR,
        "huagong-dafa/huadu":                   RED"��������"NOR,
        "huagong-dafa/huagong":                 RED"��������"NOR,
        "huagong-dafa/judu":                    RED"�ۡ�����"NOR,
        "huagong-dafa/liaodu":                  RED"�ơ�����"NOR, */

//  ��󡹦        
        "hamagong/hama":HIB"�� � ��"NOR,
        "hamagong/nizhuan":HIW"��    ת"NOR,
        "hamagong/qudu":HIW"��    ��"NOR,

// ��Ȫ��
        "lengquan-shengong/lengquan":HIB"��    Ȫ"NOR,
        "lengquan-shengong/yinyang":HIY"�����޳�"NOR,

//  �ټ�ʮ��ׯ        
        "linji-zhuang/fengyun":MAG"��    ��"NOR,
        "linji-zhuang/riyue":MAG"��    ��"NOR,
        "linji-zhuang/tiandi":HIW"��    ��"NOR,
        "linji-zhuang/wuwo":HIW"��    ��"NOR,
        "linji-zhuang/yinyang":HBBLU"��    ��"NOR,
        "linji-zhuang/zhixin":MAG"֮    ��"NOR,
        "linji-zhuang/youming":HIW"��    ڤ"NOR,

//  ���������
        "longxiang-boruo/fenchang":BLU"������"NOR,
        "longxiang-boruo/longxiang":            MAG"����֮��"NOR,
        "longxiang-boruo/shield":               CYN"��������"NOR,
        "longxiang-boruo/guiyuan":HIY"���ǹ�Ԫ"NOR,
        "longxiang-boruo/juxue":HIW"��    ��"NOR,
        "longxiang-boruo/shenyou":HIW"��    ��"NOR,

//  ������
        "jiuyang-shengong/chuangong":           HIR"��������"NOR,
        "jiuyang-shengong/jiuyang":             HIR"������"NOR,
        "jiuyang-shengong/tougu":               HIW"͸ �� ��"NOR,
        "jiuyang-shengong/yinfeng":             HIW"�� �� ��"NOR,
        "jiuyang-shengong/xinmo":            HIR"�ġ���ħ"NOR,

//  �����湦        
        "jiuyin-zhengong/huanxue":HIB"�ƾ���Ѩ"NOR,
        "jiuyin-zhengong/liaojing":HIW"�����ƾ�"NOR,
        "jiuyin-zhengong/heyi":HIR"����һ"NOR,
        "jiuyin-zhengong/jiuyin":WHT"��������"NOR,
        "jiuyin-zhengong/shehun":HIW"����"NOR,
        "jiuyin-zhengong/yihun":HIW"�ƻ��"NOR,
        "jiuyin-zhengong/zongjue":HIY"�����ܾ�"NOR,

//  ��������       
        "kurong-changong/kong":HIG"��    ��"NOR,
        "kurong-changong/ku":         GRN"���ִ�"NOR,
        "kurong-changong/liao":         HIY"��������"NOR,
        "kurong-changong/roar":         HIY"ʨ �� ��"NOR,
        "kurong-changong/rong":       HIR"���ִ�"NOR,
        "kurong-changong/xinjing":       GRN"����Ǳ��"NOR,
        
//  Ǭ��һ����
        "qiantian-yiyang/kong":HIG"��    ��"NOR,
        "qiantian-yiyang/liao":HIY"��������"NOR,
        "qiantian-yiyang/xinjing":GRN"����Ǳ��"NOR,

//  ʥ����
        "shenghuo-shengong/chuangong":          HIR"��������"NOR,
        "shenghuo-shengong/tougu":              HIW"͸ �� ��"NOR,
        "shenghuo-shengong/yinfeng":            HIW"�� �� ��"NOR,
        "shenghuo-shengong/xinmo":            HIR"�ġ���ħ"NOR,

//  ��Ԫ��        
//        "shenyuan-gong/heal":HIW"��������"NOR,
//        "shenyuan-gong/lifeheal":HIW"��������"NOR,
        "shenyuan-gong/shenyuan":HIY"�� Ԫ ��"NOR,
        
        
//        "songshan-qigong/jianqi":GRN"�� �� ��"NOR,
        
/*        "tiangang-zhengqi/heal":HIW"��������"NOR,
        "tiangang-zhengqi/lifeheal":HIW"��������"NOR,
        "tiangang-zhengqi/powerup":HIR"�� �� �"NOR, */

//  С������
        "xiaowuxiang-gong/liaojing":                  HIC"�ƾ�"NOR,
        "xiaowuxiang-gong/wuxiang":                  HBCYN+HIC"�޸�����"NOR,
        
//  �����޼���
        "xuantian-wuji/taxue":                        MAG"̤ѩ�޺�"NOR,
        "xuantian-wuji/light":                        HIW"�˹��ڽ�"NOR,

/*        
        "xixing-dafa/heal":HIW"��������"NOR,
        "xixing-dafa/lifeheal":HIW"��������"NOR,
        "xixing-dafa/powerup":HIR"���Ĵ�"NOR,
        "xixing-dafa/roar":HIR"���տ��"NOR,
        "xixing-dafa/xijing":HIR"��    ��"NOR,
        "xixing-dafa/xineili":HIR"�� �� ��"NOR,
        "xixing-dafa/xiqi":HIR"��    ��"NOR,  
*/
        
//  �׽        
        "yijin-jing/jingang":HIR"��ղ�������"NOR,
        "yijin-jing/roar":HIY"ʨ �� ��"NOR,

//  ������        
        "yinyun-ziqi/qudu":                     HIY"�����޼���"NOR,
        "yinyun-ziqi/lifesave":                 HIW"���쾢����Ծ��"NOR,
        "yinyun-ziqi/taiji":                    CYN"̫ �� ��"NOR,
        "yinyun-ziqi/yinyun":                   MAG"���ھ�"NOR,  
        
//  ��Ů�ľ�
        "yunu-xinjing/hebi":HIY"��    ��"NOR,
        "yunu-xinjing/xinjing":HIY"��    ��"NOR, 

//  ��ϼ��        
        "zixia-gong/jianyi":HIM"��ϼ����"NOR,
        "zixia-gong/zixia":MAG"��    ϼ"NOR,
        "zixia-gong/jianqi":MAG"��ϼ����"NOR,
        "zixia-gong/lifeforce":    MAG"��Ԫ�޼���"NOR,

//���վ�
           "shenzhao-jing/shenzhao":HIW"��    ��"NOR,

]);

mapping perform_names = ([
//  ��Ȼ������
        "anran-zhang/anran":HIY"��Ȼ����"NOR,
        "anran-zhang/xiaohun":HIW"����"NOR,
        "anran-zhang/jishi":HIY"��������"NOR,

//  ��Ӱ����
        "anying-fuxiang/huashen":HBYEL"���컯��"NOR,

        "banruo-zhang/yipai":RED"һ����ɢ"NOR,

//  
        "canglang-goufa/beauty":MAG"��������"NOR,
        "canglang-goufa/hero":HIR"Ӣ������"NOR,

//  �κ�ָ
        "canhe-zhi/ci":HIC"�� �� ��"NOR,

//  ���б�
        "cihang-bian/cibei":            RED"�ȱ��־�"NOR,

//  ���齣��
        "chongling-jian/hebi":          HIY"˫�����"NOR,

//  ������
        "chousui-zhang/biyan":          HIC"�̡�����"NOR,
        "chousui-zhang/chousui":          BLU"��������"NOR,
        "chousui-zhang/huoqiang":       BLU"�𡡡�ǽ"NOR,
        "chousui-zhang/huoqiu":         HIR"�𡡡���"NOR,
        "chousui-zhang/yinhuo":         YEL"��������"NOR,
        "chousui-zhang/fushidu":         BLU"��ʬ����"NOR,
//  ������
        "chuanyun-tui/chuanyun":         HIG"��    ��"NOR,


//  ��������
        "chunlan-jianfa/lianji":         HIC"��������"NOR,

//  ������
        "cuixin-zhang/cuixin":         HIR"���Ķϳ�"NOR,
        "cuixin-zhang/yinyang":         HIG"����˫��"NOR,

//  ���ħȭ
        "dafumo-quan/fumo":HIY"��   ħ"NOR,
        "dafumo-quan/xiangmo":HIG"��   ħ"NOR,
        "dafumo-quan/posha":HIY"��   ɷ"NOR,
        "dafumo-quan/qiankun":HIY"Ǭ��һ��"NOR,

//  �򹷰�
        "dagou-bang/chan":HBGRN"�� �� ��"NOR,
        "dagou-bang/zhuan":HBYEL"ת �� ��"NOR,
        "dagou-bang/shuangjue":HIW"����˫��"NOR,
        "dagou-bang/chuo":HBWHT"�� �� ��"NOR,
        "dagou-bang/tiao":HBMAG"�� �� ��"NOR,
        "dagou-bang/wugou":HIY"�����޹�"NOR,
        "dagou-bang/pi":HBRED"�� �� ��"NOR,
        "dagou-bang/ban":HBBLU"�� �� ��"NOR,
        "dagou-bang/yin":HBCYN"�� �� ��"NOR,

//  ��Ħ��
        "damo-jian/sanjue":RED"��Ħ����"NOR, 

//  ���ڴ���ӡ
        "dashou-yin/tianyin":           HIY"��������ӡ"NOR,

//  ��÷����
        "dongmei-jianfa/wumei":           HIM"��÷ŪӰ"NOR,

//  ��ת����
        "douzhuan-xingyi/xingyi":       HIY"���ƶ�ת"NOR,
        "douzhuan-xingyi/bishen":       HIG"�Ա�֮����ʩ����"NOR,

//  �μҽ���
        "duanjia-jianfa/fenglei":BLU"�����Ļ�"NOR,

//  ���¾Ž�
        "dugu-jiujian/kuangfeng":       HIC"�����"NOR,
        "dugu-jiujian/poqi":HIC"�� �� ʽ"NOR,
        "dugu-jiujian/pobian":HIW"�� �� ʽ"NOR,
        "dugu-jiujian/podao":HIW"�� �� ʽ"NOR,
        "dugu-jiujian/pozhang":HIW"�� �� ʽ"NOR,
        "dugu-jiujian/pojian":HIW"�� �� ʽ"NOR,
        "dugu-jiujian/pojianshi":HIW"�� �� ʽ"NOR,
        "dugu-jiujian/poqiang":HIW"�� ǹ ʽ"NOR,
        "dugu-jiujian/posuo":HIW"�� �� ʽ"NOR,
        "dugu-jiujian/zongjue":HIW"�� �� ʽ"NOR,

//  ������
        "duoming-jinhua/huayu":         HIW"���컨��"NOR,

//  �����ǵ�
        "fanliangyi-dao/hebi":          HIY"�ϡ����"NOR,
        "fanliangyi-dao/sanshenfeng":HIC"���������"NOR,

        "fengmo-zhang/feizhang":HIR"��    ��"NOR,

//  ��������
        "hanbing-mianzhang/xixue":      HIC"��Ѫ����"NOR,

//  ��������
        "hanbing-shenzhang/hanbing":BLU"��������"NOR,

        "hansha-sheying/xiangyin":HIY"������ӡ"NOR,

//  ��������
        "huagu-mianzhang/bujue":HIC"���಻��"NOR,
        "huagu-mianzhang/huagu":HIY"��    ��"NOR,
        "huagu-mianzhang/puhuo":RED"�ɶ��˻�"NOR,

//  ��ɽ����
//        "huashan-jianfa/jianzhang":HIR"����������"NOR,
        "huashan-jianfa/feijian":HIC"��    ��"NOR,
        "huashan-jianfa/lianhuan":      MAG"�����������ɽ�"NOR,
        "huashan-jianfa/wushuang":HIR"��˫�޶�"NOR,
        "huashan-jianfa/xiyi":HIC"ϣ�Ľ���"NOR,
        "huashan-jianfa/sanqingfeng":HIR"̫�������"NOR,
        "huashan-jianfa/yangwu":MAG"���ὣ��"NOR,
        "huashan-jianfa/shunv":HIC"��Ů����"NOR,
        "huashan-jianfa/junzi":HIC"���ӽ���"NOR,
        "huashan-jianfa/shijiushi":HIC"��Ůʮ��ʽ"NOR,
        "huashan-jianfa/kuaijian":HIG"���콣"NOR,

//  �ط�޷�
        "huifeng-bian/huixuan":HIY"����ʮ��ʽ"NOR,

//  �ط������
        "huifeng-jian/jue":HIW"��    ��"NOR,
        "huifeng-jian/liaoyuan":HIW"��ԭ�ٻ�"NOR,
        "huifeng-jian/mie":HIW"��    ��"NOR,
        "huifeng-jian/miejue":HIW"����ķ�"NOR,

// ���ҵ���
        "hujia-daofa/feidao":HIC"�� �� ��"NOR,
        "hujia-daofa/luandao":HIR"�� �� ��"NOR,
        "hujia-daofa/roudao":HIG"�� �� ��"NOR,

//  ��Ԫ��
        "hunyuan-zhang/wuji":HIR"��Ԫ�޼�"NOR,

//  ���浶
        "huoyan-dao/daoqi":               HIY"���浶��"NOR,
        "huoyan-dao/fen":               HIR"�� �� ��"NOR,
        "huoyan-dao/ran":               HIR"ȼ �� ��"NOR,

//  ��������
        "kurong-changong/jiuchong":     BLU"�� �� ��"NOR,

//  ������Ѩ��
        "lanhua-shou/fuxue":HIC"������Ѩ"NOR,

//  ���ǽ���
//        "liangyi-jian/sanqiu":CYN"һ������"NOR,
        "liangyi-jian/hebi":MAG"˫�����"NOR,
        "liangyi-jian/hundun":HIG"���罣��"NOR,
        "liangyi-jian/jianqin":HIB"�ٽ�˫��"NOR,

        "lietian-fu/lihun":RED"�� �� ն"NOR,

//  ���浶��
        "lieyan-dao/shenghuo":          HIR"ʥ�����"NOR,

//  �貨΢��
        "lingbo-weibu/luoshen":HIG"��    ��"NOR,

//  ���߱޷�
        "lingshe-bianfa/chan":HIY"���߲�˿"NOR,
        "lingshe-bianfa/sandou":HIY"��������"NOR,

//  ���ϵ���
        "liuhe-daofa/sancai":CYN"�������ŵ�"NOR,

//  ������
        "liumai-shenjian/ciqu":MAG"��ȥ����"NOR,

//  ��ɽ������
        "liuyang-zhang/duanzhang":            WHT"��������"NOR,
        "liuyang-zhang/liuyang":          HBCYN+HIC"������"NOR,

//  ��Ҷ����
        "liuye-daofa/daozhang":            BLU"һ����˫��"NOR,
        
        "longzhua-gong/canyun":RED"������"NOR,

//  ��Ӣ����
        "luoying-zhang/bading":HIW"�θ��Ƕ�"NOR,
        "luoying-zhang/fugu":HIR"�� �� ��"NOR,
        "luoying-zhang/pikong":HIB"�� �� ��"NOR,
        "luoying-zhang/shenjian":HIM"�һ�Ӱ�����"NOR,

//  ���־�ʽ
        "jieshou-jiushi/foguang":MAG"�������"NOR,

        "jingang-quan/fumo":HIR"��շ�ħ"NOR,

//  ���߽���
        "jinshe-jianfa/kuangwu":        HIR"���߿���"NOR,

// ����������
        "jinshe-zhangfa/chanshen":        HIY"���߲���"NOR,

// ����׶��
        "jinshe-zhuifa/sheying":HIR"��Ӱ���"NOR,

// �����׹�צ
        "jiuyin-baiguzhua/jiuyin":RED"��������צ"NOR,
        "jiuyin-baiguzhua/duzhua":HIB"������צ"NOR,
        "jiuyin-baiguzhua/zhuagou":HIB"����צ��"NOR,
        "jiuyin-shenzhang/shenzhang":HIR"���ƶ���"NOR,
        "jiuyin-shenzhang/yinyang":HIG"����˫��"NOR,
        "jiuyin-shenzhua/sanjue":RED"��������ץ"NOR,
        "jiuyin-shenfa/huanyinbu":HIW"������"NOR,
        "juehu-shou/juehu":             BLU"��������"NOR,
        "kongming-quan/luanwu":RED"Ⱥħ����"NOR,
        "kongmingquan/chan":CYN"�� �� ��"NOR,
        "kongmingquan/kongqianjiuhou":CYN"��ǰ����"NOR,
        "kunlun-zhang/diezhang":HIG"���ص���"NOR,

//  ��Ůȭ��
        "meinu-quanfa/shexin":HIY"��    ��"NOR,

//  ��ҽ���
        "miaojia-jianfa/duoming":HIW"����������"NOR,
        "miaojia-jianfa/ci":HBBLU+HIW"��  ��  ��"NOR,

//  Ľ�ݵ���
        "murong-daofa/daoying":HIR"�� Ӱ ��"NOR,

//  Ľ�ݽ���
        "murong-jianfa/lianhuan":HIC"�߽�����ָ"NOR,
        "murong-jianfa/sanhua":HIG"��Ůɢ��"NOR,
//        "murong-jianfa/qixingplus":HIB"�߽�ת����"NOR,


        "nianhua-zhi/fuxue":HIY"��Ѩ����"NOR,

// ��Ѫ��צ
        "ningxue-shenzhua/ningxue":HIR"��Ѫ��"NOR,
        "ningxue-shenzhua/liao":HIY"���־�"NOR,

        "pangen-cuojie/pifeng":HIR"�� �� ��"NOR,
        "pixie-jian/cimu":            RED"�����Ŀ"NOR,
        "pixie-jian/feiying":         MAG"������Ӱ��"NOR,
        "pixie-jian/jue":             MAG"�� �� ��"NOR,

//  ��ʯ����ȭ
        "poyu-quan/leidong":MAG"�׶�����"NOR,

//  Ǭ����Ų��
        "qiankun-danuoyi/hua":           HIW"�� �� ��"NOR,
        "qiankun-danuoyi/yi":           BLU"�� �� ��"NOR,
        "qiankun-danuoyi/xu":           HIY"�� �� ��"NOR,
        "qiankun-danuoyi/yin":           HIG"�� �� ��"NOR,

//  ����ǧҶ��
        "qianye-shou/qianshou":HIY"ǧ������"NOR,

//  ��ս���        
        "qiuju-jianfa/chan":HBRED"�������"NOR,

"qingxu-bian/fei":HIB"����˫��"NOR,

//        "qingyan-zhang/liaorao":HIY"��������"NOR,

//  ����ȭ
        "qishang-quan/duanhun":         HIR"�ϻ����"NOR,
        "qishang-quan/qishang":         HIR"�����ܾ�"NOR,

//  ȫ�潣��
        "quanzhen-jianfa/qixing":HIW"���Ǿ�����"NOR,
        "quanzhen-jianfa/sanqing":HIW"һ��������"NOR,

        "ranmu-daofa/fentian":HIR"�ٻ����"NOR,
        "ranmu-daofa/fenwo":HIR"��    ��"NOR,
        "ranmu-daofa/fenxin":HIR"�� �� ��"NOR,
        "riyue-bian/chanrao":HIY"�� �� ��"NOR,
        "riyue-bian/fumoquan":HIY"��շ�ħȦ"NOR,
        "riyue-bian/riyue":HIC"�������"NOR,
        "ruying-suixingtui":YEL"��Ӱ����"NOR,
        "sanhua-zhang/sanhua":HIW"�ļ�ɢ��"NOR,

//  �������ץ
        "sanyin-zhua/sanyin":           HBBLU"��������ץ"NOR,

//  ʥ���    
"shenghuo-lingfa/duo":          BCYN"�� �� ��"NOR,
        "shenghuo-lingfa/ji":           HIY"�� �� ��"NOR,
        "shenghuo-lingfa/tisha":        HIM"�ߡ���ɳ"NOR,
        "shenghuo-lingfa/xinmo":        HIR"�ġ���ħ"NOR,

//  ����׷����
        "shenlong-tuifa/zhuiming":HIY"����׷����"NOR,

//  ˮ��Ư
        "shuishangpiao/piao":HIC"Ư"NOR,

//  �Ļ���Ӱ��
        "sihua-wuying/chan":HBRED"�������"NOR,
        "sihua-wuying/lianji":HIC"��������"NOR,
        "sihua-wuying/wuqing":HIR"������"NOR,
        "sihua-wuying/wumei":HIM"��÷ŪӰ"NOR,
        "sihua-wuying/tongqi":HIG"ͬ����֦"NOR,


//  ��ɽ����
        "songshan-jian/feiwu":BLU"��    ��"NOR,
        "songshan-jian/leiting":YEL"�������"NOR,
        "songshan-jian/longfeng":HIR"��������"NOR,
        "songshan-jian/songyang":HIW"�� �� ��"NOR,

//  ����������
        "songyang-zhang/junji":CYN"��������"NOR,

//  ��������
        "songyang-shou/junji":CYN"��������"NOR,
        "songyang-shou/yinyang":HIY"��������"NOR,

// ������
        "songyang-bian/luan":BLU"�� �� ��"NOR,


        "suibo-zhuliu/wuzhuan":HIW"������ת"NOR,
        "suishangpiao/piao":HIC"   Ʈ  "NOR,

//  ̫����
        "taiji-jian/chan":              HIW"������ƾ�"NOR,
        "taiji-jian/lian":              CYN"�� �� ��"NOR,
        "taiji-jian/lianhuan":              HIC"�� �� ��"NOR,
        "taiji-jian/sanhuan":           HIG"��������"NOR,
        "taiji-jian/tongshou":          HIC"���ͬ��"NOR,
        "taiji-jian/raozhi":           HIR"��ָ�ὣ"NOR,

//  ̫��ȭ
        "taiji-quan/ji":                RED"�� �� ��"NOR,
        "taiji-quan/luanhuan":          HIC"�� �� ��"NOR,
        "taiji-quan/zhen":              RED"�� �� ��"NOR,
        "taiji-quan/an":              HIB"�� �� ��"NOR,
        "taiji-quan/dongjing":              MAG"�� �� ��"NOR,
        "taiji-quan/gangrou":              HIB"�� �� ��"NOR,
        "taiji-quan/yinyang":              GRN"�� �� ��"NOR,
        "taiji-quan/zhannian":              CYN"ճ ճ ��"NOR,
        "taiji-quan/taiji":              WHT"̫    ��"NOR,

//  ��ָ��ͨ
        "tanzhi-shentong/huayu":CYN"���컨��"NOR,
        "tanzhi-shentong/qiankun":HIG"Ǭ��һָ"NOR,
        "tanzhi-shentong/shentong":HIW"��ָ��ͨ"NOR,
        "tanzhi-shentong/tan":HIG"�� �� ��"NOR,
        "tanzhi-shentong/xinghe":HIW"�Ǻ�ǧ����"NOR,


//  ����ذ��
        "tenglong-bifa/diqing":HIY"���ཱུ��"NOR,
        "tenglong-bifa/feiyan":HIR"�������"NOR,
        "tenglong-bifa/guifei":HIR"��������"NOR,
        "tenglong-bifa/luda":HIY"³�����"NOR,
        "tenglong-bifa/xiaolian":HIR"С�����"NOR,
        "tenglong-bifa/zixu":HIY"����ٶ�"NOR,

        "tiangang-jian/qixinggongyue":YEL"���ǹ���"NOR,
        "tiangang-zhang/tiangang":HIG"��    �"NOR,

//  ��ɽ�ȷ�
        "tianshan-zhang/feizhi":        BLU"����"NOR,

//        "tianyu-qijian/san":HIR"��Ůɢ��"NOR,

//  �����Ʒ�
        "tiezhang-zhangfa/tianlei":HIY"�� �� ��"NOR,
        "tiezhang-zhangfa/duoming":HBBLU"������צ"NOR,
        "tiezhang-zhangfa/heisha":HBBLU"�� ɰ ��"NOR,
        "tiezhang-zhangfa/heyi":HIW"������һ"NOR,
        "tiezhang-zhangfa/honglei":HBBLU"����˫��"NOR,
        "tiezhang-zhangfa/judu":HIB"��    ��"NOR,
        "tiezhang-zhangfa/pangen":HBBLU"�����̸�"NOR,
        "tiezhang-zhangfa/pushan":HIW"��������"NOR,
        "tiezhang-zhangfa/qinna":HBBLU"��������"NOR,
        "tiezhang-zhangfa/rubairen":HBBLU"�� �� ��"NOR,
        "tiezhang-zhangfa/tiezhang":HBBLU"��    ��"NOR,
        "tiezhang-zhangfa/xuanfeng":HBBLU"�������"NOR,
        "tiezhang-zhangfa/zhangdao":HIW"�����Ƶ�"NOR,

//  ������
        "tiyunzong/zong":               HIY"���־�"NOR,

//  �廢���ŵ�
        "wuhu-duanmendao/duan":HIY"���־�"NOR,

//  ��ս�����
        "xiangfu-lun/dazhuan":          HIY"���ִ�ת"NOR,
        "xiangfu-lun/wushuai":          HIY"������˥"NOR,

//  ����ʮ����
        "xianglong-zhang/kanglong":HIC"�����л�"NOR,
        "xianglong-zhang/paiyun":WHT"����˫��"NOR,
        "xianglong-zhang/xiao":YEL"�� �� Х"NOR,

//  ���񽣷�
        "xiazhu-jianfa/wuqing":HIR"������"NOR,


//  ������
        "xingyi-zhang/riyue":CYN"����ͬ��"NOR,
//        "xingyi-zhang/xingdian":HIW"�ǹ���"NOR,

//  ����ɨҶ��
        "xuanfeng-tui/kuangfeng":HIG"������"NOR,

//  ��������
        "xuantie-jianfa/haichao":HIB"������ӿ"NOR,
        "xuantie-jianfa/wujian":HIB"�޽�ʤ�н�"NOR,

//  ���鵶��
        "xuanxu-daofa/luanhuanjue":        HIY"�� �� ��"NOR,

//  ��������
        "xuanyin-jian/xuanyin":        HIB"�� �� ��"NOR,
        "xuanyin-jian/zhan":        HIB"ն �� ��"NOR,
        "xuanyin-jian/jiulianji":        HIR"����������"NOR,


//  Ѫ����
        "xuedao-jing/jixue":            HIR"��Ѫ��"NOR,
        "xuedao-jing/shendao":          HIR"�񵶴���"NOR,

//  ���е���
        "yanxing-daofa/feiyan":HIY"���������"NOR,
        "yanxing-daofa/chuanliu":HIY"���д�����"NOR,
        "yanxing-daofa/hebi":MAG"˫�����"NOR,
        "yanxing-daofa/huanying":HIY"���λ�Ӱ"NOR,

//  ����������
        "yinlong-bian/chanrao":HIG"���ƾ�"NOR,
        "yinlong-bian/feilong":HIG"������"NOR,
        "yinlong-bian/chou":HIB"���־�"NOR,

        "yingou-bifa/caoshu":HIM"��    ��"NOR,
        "yingou-bifa/kaishu":HIC"��    ��"NOR,
        "yingou-bifa/shigu":HIY"ʯ �� ��"NOR,

//  ��������
        "yinsuo-jinling/sanwu":HIW"����������"NOR,
        "yinsuo-jinling/yueyin":HIW"��������"NOR,
//        "yinsuo-jinling/feng":HIC"��    Ѩ"NOR,
        "yinsuo-jinling/yufeng":HIW"�� �� ��"NOR,

//  һ��ָ
        "yiyang-zhi/ciqu":HIG"��ȥ����"NOR,
        "yiyang-zhi/yizhisanmai":HIR"һָ������"NOR,
        "yiyang-zhi/liumai":HIW"������"NOR,
        "yiyang-zhi/sandie":HIY"��������"NOR,
        "yiyang-zhi/qianlong":           WHT"Ǳ������"NOR,

//  һָ��
        "yizhi-chan/wofo":              HIW"����ҷ�"NOR,

//  ������
        "youlong-shenfa/baibian":HIY"���аٱ�"NOR,

        "youming-zhao/youming":HIR"�������"NOR,
        "yubi-jianfa/san":              HIM"��Ůɢ��"NOR,
        "yubi-jianfa/shuangzhao":       HIG"�Ӱ˫��"NOR,

//  ��Ů���Ľ�
        "yunu-jianfa/hebi":HIY"˫���ϱ�"NOR,        
        "yunu-jianfa/suxin":HIW"��Ů����"NOR,        
        "yuxiao-jian/feiying":HIW"��    Ӱ"NOR,
        "yuxiao-jian/qimen":HIG"��������"NOR,
//        "yuxiao-jian/yuxiao":CYN"�̺�����������"NOR,

//  ��ɽ��÷��
        "zhemei-shou/luanmei":           MAG"��÷����"NOR,
        "zhemei-shou/zhe":           HIY"���־�"NOR,
        "zhemei-shou/duo":           CYN"���ֶ���"NOR,
        "zhemei-shou/hanmei":           HIM"��÷ů��"NOR,
        "zhemei-shou/jue":           HIY"��÷���ľ�"NOR,
        "zhemei-shou/poyun":           CYN"��������ʽ"NOR,
        "zhemei-shou/tanmei":           HIY"��÷����ѩ��ɢ����"NOR,

//  ��ɽ����
        "zhenshan-mianzhang/bingdi":    HIC"��������"NOR,

        "zhuihun-gou/luanpifeng":       HIB"�� �� ��"NOR,
        "zui-gun/zuida":HIY"�������"NOR,
        "zuibaxian/zuijiu":GRN"�������"NOR,

//ǧ������
        "qianzhu-wandushou/qianzhu":HIR"ǧ"HIG"��"HIW"��"HIB"��"NOR,  

//����ȭ
        "kongming-quan/kong":HIW"�� �� ��"NOR,  
        "kongming-quan/ming":HIW"�� �� ��"NOR,  

]);

