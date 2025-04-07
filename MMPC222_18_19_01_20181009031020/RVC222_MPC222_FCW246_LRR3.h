#ifndef RVC222_MPC222_FCW246_LRR3_H
#define RVC222_MPC222_FCW246_LRR3_H

#include "parameterprovider_mmpc222_18_19_01_20181009031020.h"

class RVC222_MPC222_FCW246_LRR3 {
public:
    explicit RVC222_MPC222_FCW246_LRR3(std::shared_ptr<IParameterProvider> provider)
        : provider_(std::move(provider)) {
        provider_->initializeParameters();
    }

    VKeyGenResultEx GenerateKey(const std::vector<uint8_t>& input,
                                int paramInt,
                                const std::string& /*unused1*/,
                                const std::string& /*unused2*/,
                                std::vector<uint8_t>& output,
                                Parameter<int>& paramOutLen) {
        if (input.size() < 4 || output.size() < 4) {
            return VKeyGenResultEx::KGRE_BufferToSmall;
        }

        if (!InitializeParameters(paramInt)) {
            return VKeyGenResultEx::KGRE_UnspecifiedError;
        }

        uint64_t l1 = 0;
        l1 |= static_cast<uint64_t>(input[3]) & 0xFF;
        l1 |= static_cast<uint64_t>(input[2] & 0xFF) << 8;
        l1 |= static_cast<uint64_t>(input[1] & 0xFF) << 16;
        l1 |= static_cast<uint64_t>(input[0] & 0xFF) << 24;

        uint64_t l2 = l1;
        l2 |= mAConst_;
        l2 ^= mBConst_;
        l2 += mCConst_;
        l2 ^= 0xFFFFFFFFFFFFFFFFULL;

        output[0] = static_cast<uint8_t>((l2 >> 24) & 0xFF);
        output[1] = static_cast<uint8_t>((l2 >> 16) & 0xFF);
        output[2] = static_cast<uint8_t>((l2 >> 8) & 0xFF);
        output[3] = static_cast<uint8_t>(l2 & 0xFF);

        paramOutLen.data = 4;
        return VKeyGenResultEx::KGRE_Ok;
    }

private:
    bool InitializeParameters(int paramInt) {
        mAConstBytes_.resize(4);
        if (!provider_->GetByteArray("A", paramInt, mAConstBytes_))
            return false;
        mAConst_ = toUint32(mAConstBytes_);

        mBConstBytes_.resize(4);
        if (!provider_->GetByteArray("B", paramInt, mBConstBytes_))
            return false;
        mBConst_ = toUint32(mBConstBytes_);

        mCConstBytes_.resize(4);
        if (!provider_->GetByteArray("C", paramInt, mCConstBytes_))
            return false;
        mCConst_ = toUint32(mCConstBytes_);

        qDebug() << "[BYTES] " << mAConstBytes_ << mBConstBytes_ << mCConstBytes_;
        qDebug() << "[CONST] " << mAConst_ << mBConst_ << mCConst_;

        return true;
    }

    uint32_t toUint32(const std::vector<uint8_t>& bytes) const {
        if (bytes.size() < 4) return 0;
        return (static_cast<uint32_t>(bytes[0]) << 24) |
               (static_cast<uint32_t>(bytes[1]) << 16) |
               (static_cast<uint32_t>(bytes[2]) << 8)  |
               (static_cast<uint32_t>(bytes[3]));
    }

private:
    std::shared_ptr<IParameterProvider> provider_;

    std::vector<uint8_t> mAConstBytes_;
    std::vector<uint8_t> mBConstBytes_;
    std::vector<uint8_t> mCConstBytes_;

    uint64_t mAConst_ = 0;
    uint64_t mBConst_ = 0;
    uint64_t mCConst_ = 0;
};

#endif // RVC222_MPC222_FCW246_LRR3_H
